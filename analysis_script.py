#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Script phân tích edge case trong 105 bài nộp (7 nhóm × 15 bài)
Lớp 253COMP1013GD01 - Tuần 2 HK Hè 2025-2026
"""

import os
import re
import json
from pathlib import Path
from collections import defaultdict
from datetime import datetime

try:
    from docx import Document
    HAS_DOCX = True
except ImportError:
    HAS_DOCX = False

REPO_ROOT = Path(__file__).parent
GROUPS = {
    "N1": ("Nhóm 1", "cpp"),
    "N2": ("Nhóm 2", "cpp"),
    "N3": ("Nhóm 3", "docx"),
    "N4": ("Nhóm 4", "cpp"),
    "N5": ("Nhóm 5", "cpp"),
    "N6": ("Nhóm 6", "docx"),
    "N7": ("Nhóm 7", "cpp"),
}

EDGE_CASES = {
    "negative_numbers": {
        "patterns": [r"if\s*\(\s*\w+\s*<\s*0", r"negative", r"âm"],
        "description": "Kiểm tra số âm",
        "severity": "high",
    },
    "zero_division": {
        "patterns": [r"if\s*\(\s*\w+\s*!=\s*0", r"divide.*zero", r"chia.*0"],
        "description": "Xử lý chia cho 0",
        "severity": "high",
    },
    "boundary_check": {
        "patterns": [r"(INT_MAX|INT_MIN|MAX|MIN)", r"boundary", r"overflow"],
        "description": "Kiểm tra giá trị biên",
        "severity": "medium",
    },
    "date_validation": {
        "patterns": [r"day.*<=.*31", r"month.*<=.*12", r"leap", r"isLeap"],
        "description": "Kiểm tra ngày tháng hợp lệ",
        "severity": "high",
    },
    "triangle_inequality": {
        "patterns": [r"a\s*\+\s*b\s*>\s*c", r"isTriangle", r"triangle"],
        "description": "Kiểm tra bất đẳng thức tam giác",
        "severity": "high",
    },
    "empty_input": {
        "patterns": [r"empty", r"null", r"nullptr", r"cin\.fail"],
        "description": "Xử lý input rỗng",
        "severity": "medium",
    },
    "type_checking": {
        "patterns": [r"stoi|stof|stod", r"float.*int", r"kiểu.*dữ"],
        "description": "Kiểm tra kiểu dữ liệu",
        "severity": "medium",
    },
}

def extract_cpp_from_docx(docx_path):
    if not HAS_DOCX:
        return None
    try:
        doc = Document(docx_path)
        code_blocks = []
        for para in doc.paragraphs:
            text = para.text.strip()
            if text:
                code_blocks.append(text)
        return "\n".join(code_blocks) if code_blocks else None
    except:
        return None

def read_cpp_file(cpp_path):
    try:
        with open(cpp_path, 'r', encoding='utf-8') as f:
            return f.read()
    except:
        return None

def get_code_content(file_path):
    if file_path.endswith('.cpp'):
        return read_cpp_file(file_path)
    elif file_path.endswith('.docx'):
        return extract_cpp_from_docx(file_path)
    return None

class EdgeCaseAnalyzer:
    def __init__(self):
        self.results = {}
        for case in EDGE_CASES:
            self.results[case] = {"found": 0, "missing": 0, "files": []}
        self.file_issues = defaultdict(list)
        self.total_files = 0
        self.total_issues = 0

    def check_edge_case(self, code, case_name):
        if not code:
            return False
        patterns = EDGE_CASES[case_name]["patterns"]
        for pattern in patterns:
            if re.search(pattern, code, re.IGNORECASE):
                return True
        return False

    def analyze_file(self, file_path, file_name, group_code):
        code = get_code_content(file_path)
        if not code:
            return False
        self.total_files += 1
        issues = []
        for case_name in EDGE_CASES:
            if self.check_edge_case(code, case_name):
                self.results[case_name]["found"] += 1
                self.results[case_name]["files"].append(f"{group_code}/{file_name}")
            else:
                self.results[case_name]["missing"] += 1
                issues.append({
                    "case": case_name,
                    "severity": EDGE_CASES[case_name]["severity"],
                    "description": EDGE_CASES[case_name]["description"]
                })
                self.total_issues += 1
        if issues:
            self.file_issues[f"{group_code}/{file_name}"] = issues
        return True

    def analyze_group(self, group_code):
        group_dir = REPO_ROOT / group_code
        if not group_dir.exists():
            return 0
        ext = GROUPS[group_code][1]
        files = list(group_dir.glob(f"*.{ext}"))
        if files:
            print(f"✅ {GROUPS[group_code][0]:15} ({group_code}): {len(files):2} file .{ext}")
        for file_path in sorted(files):
            self.analyze_file(file_path, file_path.name, group_code)
        return len(files)

    def generate_report(self):
        print("\n" + "="*80)
        print("📊 BÁO CÁO PHÂN TÍCH EDGE CASE")
        print("="*80)
        print(f"\n📈 THỐNG KÊ CHUNG:")
        print(f"   • Tổng file phân tích: {self.total_files}/105")
        print(f"   • Tổng vấn đề: {self.total_issues}")
        print(f"   • Ngày: {datetime.now().strftime('%d/%m/%Y %H:%M:%S')}")
        print(f"\n🔍 CHI TIẾT:")
        print(f"{'Loại Edge Case':<35} {'Tìm thấy':>8} {'Thiếu':>8}")
        print("-" * 60)
        
        for case, stats in sorted(self.results.items()):
            found = stats["found"]
            missing = stats["missing"]
            case_display = EDGE_CASES[case]["description"][:32]
            severity = "🔴" if EDGE_CASES[case]["severity"] == "high" else "🟡"
            print(f"{severity} {case_display:<32} {found:>8} {missing:>8}")
        
        print("-" * 60)
        total_found = sum(s['found'] for s in self.results.values())
        total_missing = sum(s['missing'] for s in self.results.values())
        print(f"{'TỔNG':<35} {total_found:>8} {total_missing:>8}")
        
        print(f"\n⚠️  FILE CÓ VẤN ĐỀ ({len(self.file_issues)}):")
        if self.file_issues:
            for file_name in sorted(self.file_issues.keys())[:20]:
                print(f"\n   📄 {file_name}")
                for issue in self.file_issues[file_name]:
                    severity = "🔴" if issue["severity"] == "high" else "🟡"
                    print(f"      {severity} {issue['description']}")
        else:
            print("   ✅ Tất cả file đều có xử lý!")
        
        return total_missing

def main():
    print("="*80)
    print("🚀 PHÂN TÍCH EDGE CASE - LỚP 253COMP1013GD01")
    print("="*80)
    print(f"📍 Repo: TonyTheSlacker/XSTK")
    print(f"📂 Thư mục: {REPO_ROOT}")
    print("="*80)
    
    analyzer = EdgeCaseAnalyzer()
    print("\n📂 QUÉT NHÓM:")
    
    for group_code in sorted(GROUPS.keys()):
        analyzer.analyze_group(group_code)
    
    if analyzer.total_files == 0:
        print("\n❌ Không tìm thấy file nào!")
        return
    
    analyzer.generate_report()
    
    output_file = REPO_ROOT / "edge_case_analysis_report.json"
    try:
        with open(output_file, 'w', encoding='utf-8') as f:
            json.dump({
                "timestamp": datetime.now().isoformat(),
                "total_files": analyzer.total_files,
                "results": analyzer.results,
                "issues": dict(analyzer.file_issues)
            }, f, indent=2, ensure_ascii=False)
        print(f"\n💾 Báo cáo JSON: {output_file}")
    except:
        pass
    
    print("\n✅ Hoàn thành!")

if __name__ == "__main__":
    main()
