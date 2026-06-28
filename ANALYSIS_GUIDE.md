# 📊 Hướng Dẫn Phân Tích Edge Case

## 🎯 Mục Đích
Phân tích **105 bài nộp** (7 nhóm × 15 bài) của lớp **253COMP1013GD01** để tìm ra những **edge case bị thiếu hoặc xử lý sai** trong bài tập lập trình C++.

### Edge Cases Được Kiểm Tra:
1. **🔴 Số âm** (Negative numbers) - Severity: HIGH
   - Kiểm tra: `if (x < 0)`
   
2. **🔴 Chia cho 0** (Zero division) - Severity: HIGH
   - Kiểm tra: `if (divisor != 0)`, `if (x == 0)`
   
3. **🟡 Giá trị biên** (Boundary values) - Severity: MEDIUM
   - Kiểm tra: `INT_MAX`, `INT_MIN`, overflow/underflow
   
4. **🔴 Ngày tháng hợp lệ** (Date validation) - Severity: HIGH
   - Kiểm tra: `(day >= 1 && day <= 31)`, năm nhuận, etc.
   
5. **🔴 Bất đẳng thức tam giác** (Triangle inequality) - Severity: HIGH
   - Kiểm tra: `(a + b > c) && (a + c > b) && (b + c > a)`
   
6. **🟡 Input rỗng** (Empty input) - Severity: MEDIUM
   - Kiểm tra: `cin.fail()`, `getline()`, `null/nullptr`
   
7. **🟡 Kiểu dữ liệu** (Type checking) - Severity: MEDIUM
   - Kiểm tra: `stoi()`, `stof()`, `stod()`, type conversion

---

## 🚀 Cách Sử Dụng

### Bước 1: Cài Đặt Dependencies
```bash
pip install -r requirements.txt
```

### Bước 2: Chuẩn Bị Dữ Liệu

**Cấu trúc thư mục cần có:**
```
XSTK/
├── N1/              (Nhóm 1)
│   ├── 1.cpp
│   ├── 2.cpp
│   └── ...
├── N2/              (Nhóm 2)
│   ├── 1.cpp
│   └── ...
├── N3/              (Nhóm 3 - nộp .docx)
│   ├── BAI01.docx
│   ├── BAI02.docx
│   └── ...
├── N4/              (Nhóm 4)
├── N5/              (Nhóm 5)
├── N6/              (Nhóm 6 - nộp .docx)
├── N7/              (Nhóm 7)
├── analysis_script.py
├── requirements.txt
└── ANALYSIS_GUIDE.md
```

### Bước 3: Chạy Script
```bash
python analysis_script.py
```

### Bước 4: Xem Kết Quả

**Output sẽ hiển thị:**
1. **Console:** Bảng thống kê chi tiết + danh sách file có vấn đề
2. **`edge_case_analysis_report.json`:** Báo cáo chi tiết dạng JSON
3. **`EDGE_CASE_ANALYSIS.md`:** Báo cáo dạng Markdown

---

## 📋 Ví Dụ Output

```
================================================================================
🚀 PHÂN TÍCH EDGE CASE - LỚP 253COMP1013GD01
================================================================================
📍 Repo: TonyTheSlacker/XSTK
📂 Thư mục: /path/to/XSTK
⏰ Thời gian: 28/06/2026 16:15:30
================================================================================

📂 QUÉT NHÓM:
✅ Nhóm 1         (N1): 15 file .cpp
✅ Nhóm 2         (N2): 15 file .cpp
⚠️  Nhóm 3         (N3):  0 file .docx
✅ Nhóm 4         (N4): 15 file .cpp
✅ Nhóm 5         (N5): 15 file .cpp
⚠️  Nhóm 6         (N6):  0 file .docx
✅ Nhóm 7         (N7): 15 file .cpp

================================================================================
📊 BÁO CÁO PHÂN TÍCH EDGE CASE
================================================================================

📈 THỐNG KÊ CHUNG:
   • Tổng file phân tích: 90/105 (kỳ vọng)
   • Tổng vấn đề tìm thấy: 156
   • Ngày phân tích: 28/06/2026 16:15:30

🔍 CHI TIẾT PHÁT HIỆN EDGE CASE:
Loại Edge Case                     Tìm thấy   Thiếu    %
------------------------------------------------------------
🔴 Kiểm tra số âm                       25      65  27.8%
🔴 Xử lý chia cho 0                     18      72  20.0%
🟡 Kiểm tra giá trị biên                35      55  38.9%
🔴 Kiểm tra ngày tháng hợp lệ           40      50  44.4%
🔴 Kiểm tra bất đẳng thức tam giác       50      40  55.6%
🟡 Xử lý input rỗng/không hợp lệ        20      70  22.2%
🟡 Kiểm tra/chuyển đổi kiểu dữ liệu     30      60  33.3%
------------------------------------------------------------
TỔNG CỘNG                             218     412  34.6%

⚠️  DANH SÁCH FILE CÓ VẤN ĐỀ (45):

   📄 N1/9.cpp
      🔴 Kiểm tra số âm
      🔴 Xử lý chia cho 0

   📄 N2/14.cpp
      🔴 Kiểm tra ngày tháng hợp lệ
```

---

## 🔧 Cách Xử Lý File .docx (N3, N6)

### Option A: Tự Động (Khuyến Nghị)
Script sẽ **tự động extract text** từ `.docx` bằng `python-docx`

### Option B: Thủ Công
1. Mở file `.docx` bằng MS Word
2. Copy code từ doc
3. Paste vào file `.cpp` tương ứng
   - Ví dụ: `N3/BAI01.cpp`, `N3/BAI02.cpp`, etc.

### Option C: Convert Online
- Dùng [CloudConvert](https://cloudconvert.com/docx-to-txt) để convert `.docx` → `.txt`
- Sau đó copy code vào `.cpp`

---

## 📊 Hiểu Kết Quả

### Severity Levels:
- 🔴 **HIGH** (Cao): Edge case quan trọng, nên xử lý
- 🟡 **MEDIUM** (Trung bình): Nên xem xét

### Thông Dịch Kết Quả:
- **Tìm thấy (Found)**: Số file XỬ LÝ edge case này ✅
- **Thiếu (Missing)**: Số file KHÔNG xử lý edge case này ❌
- **%**: Tỷ lệ % file có xử lý

---

## 💡 Ví Dụ Sửa Lỗi

### Trước (Thiếu edge case):
```cpp
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        cout << "Valid triangle\n";
    }
    return 0;
}
```

### Sau (Có edge case):
```cpp
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    // Kiểm tra số âm
    if (a <= 0 || b <= 0 || c <= 0) {
        cout << "Invalid: sides must be positive\n";
        return 1;
    }
    
    // Kiểm tra bất đẳng thức tam giác
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        cout << "Valid triangle\n";
    } else {
        cout << "Invalid triangle\n";
    }
    return 0;
}
```

---

## 📝 Output Files

| File | Mô Tả |
|------|-------|
| `edge_case_analysis_report.json` | Báo cáo JSON chi tiết |
| `EDGE_CASE_ANALYSIS.md` | Báo cáo Markdown |
| Console output | Thống kê nhanh |

---

## ❓ Troubleshooting

### Vấn đề: "ModuleNotFoundError: No module named 'docx'"
```bash
pip install python-docx
```

### Vấn đề: "No module named 'analysis_script'"
Đảm bảo chạy từ **thư mục repo root**:
```bash
cd /path/to/XSTK
python analysis_script.py
```

### Vấn đề: Không tìm thấy file
Kiểm tra cấu trúc thư mục:
```bash
ls -la N1/  # Xem file trong N1
ls -la N3/  # Xem file trong N3
```

---

## 📞 Support

Nếu có lỗi, chạy với verbose mode:
```bash
python analysis_script.py -v
```

---

## 📄 Liên Hệ

- **Lớp:** 253COMP1013GD01
- **Trường:** Đại học Sư phạm TP.HCM
- **Học kỳ:** Hè 2025-2026
- **Tuần:** Thực hành Tuần 2
