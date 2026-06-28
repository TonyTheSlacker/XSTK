# 📊 PHÂN TÍCH EDGE CASE - TẤT CẢ 7 NHÓM (N1-N7)

## 📈 BẢNG XẾP HẠNG TỔNG QUÁT

| Xếp hạng | Nhóm | Chất lượng | Edge Case | Ghi chú |
|---|---|---|---|---|
| 🥇 **1** | **N7** | ⭐⭐⭐⭐⭐ | Xuất sắc | Code sạch, xử lý toàn diện |
| 🥈 **2** | **N3** | ⭐⭐⭐⭐ | Rất tốt | Hầu hết bài check edge case |
| 🥉 **3** | **N1** | ⭐⭐⭐ | Tốt | Kiểm tra cơ bản, thiếu vài bài |
| **4** | **N6** | ⭐⭐ | Trung bình | Nhiều bài không check input |
| **5** | **N2** | ⭐⭐ | Trung bình | Formula taxi chính xác nhưng bài khác yếu |
| **6** | **N4** | ⭐⭐ | Trung bình | Dùng struct nhưng logic yếu |
| **7** | **N5** | ⭐ | Yếu | Thiếu kiểm tra, taxi tính sai |

---

## 🔍 PHÂN TÍCH CHI TIẾT NHÓM 6

### **NHÓM 6 - CÁC VẤN ĐỀ CHÍNH:**

| Bài | Nội dung | Vấn đề Edge Case | Mức độ |
|---|---|---|---|
| **1-2** | Tính toán `++/--` | Không có input validation | ✅ |
| **3** | Tính toán | Không có input validation | ✅ |
| **4** | In 2 số | **Không in số lớn hơn!** (chỉ in 2 số) | 🔴 **THIẾU** |
| **5** | Sắp xếp 3 số | ❌ **BUG**: Thiếu 1 bước swap! | 🔴 **CRITICAL** |
| **6** | Sắp xếp 3 số | ✅ Tốt | ✅ |
| **7** | Vị trí chữ số lớn nhất | ❌ **Chỉ in hàng trăm (`c`)** | 🔴 **THIẾU** |
| **8** | Sắp xếp chữ số | ✅ Tốt | ✅ |
| **9** | Kiểm tra ngày (năm nhuận) | ✅ Check `y <= 0` + switch/case đầy đủ | ⭐⭐⭐ |
| **10** | Kiểm tra giờ | ✅ Check hợp lệ | ⭐⭐⭐ |
| **11** | Kiểm tra năm nhuận | ✅ Tốt như bài 9 | ⭐⭐⭐ |
| **12** | Diện tích & chu vi | ❌ **KHÔNG check canh/bán kính <= 0** + **chu vi HCN sai**: `(a+b)/2` thay vì `2*(a+b)` | 🔴 **CRITICAL** |
| **13** | Tính tiền taxi | ❌ **KHÔNG hoàn thành**, logic sai hoàn toàn | 🔴 **CRITICAL** |
| **14** | Kiểm tra tam giác | ❌ **Logic dư thừa**: `(a==b&&a==c)\|\|(b==c&&b==a)` là sai | 🟡 **BUG LOGIC** |
| **15** | Số chính phương | ❌ **Không check n <= 0** | 🟡 **THIẾU** |

---

## 🔴 CÁC LỖI CRITICAL TRONG N6

### **1️⃣ Bài 4 - SSSAI: Chỉ in 2 số, không in số lớn**
```cpp
// ❌ N6 CODE (SAI):
#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    cout<<a<<" "<<b;  // ← Chỉ in 2 số, không xác định số nào lớn!
    return 0;
}

// ✅ ĐÚNG (So sánh rồi in):
#include <iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    if(a > b) cout << a;
    else cout << b;
    return 0;
}
```

---

### **2️⃣ Bài 5 - BUG: Thiếu bước swap thứ 2**
```cpp
// ❌ N6 CODE (SAI):
if(a>b) swap(a,b);
if(b>c) swap(b,c);
cout<<a<<b<<c;
// Test: Input 3,1,2
// Bước 1: a=1, b=3, c=2
// Bước 2: a=1, b=2, c=3
// Output: 123 ✅ (May mà đúng!)
// 
// Test: Input 3,2,1
// Bước 1: a=2, b=3, c=1
// Bước 2: a=2, b=1, c=3  ← b > c nên swap
// Output: 213 ❌ (SAI!)

// ✅ ĐÚNG (Phải có 3 bước):
if(a>b) swap(a,b);
if(b>c) swap(b,c);
if(a>b) swap(a,b);  // ← KHÔNG ĐƯỢC THIẾU!
cout<<a<<b<<c;
```

---

### **3️⃣ Bài 7 - SAI: Chỉ in hàng trăm**
```cpp
// ❌ N6 CODE (SAI):
int a=n%10, b=(n/10)%10, c=n/100;
if(a>b) swap(a,b);
if(b>c) swap(b,c);
cout<<c;  // ← Chỉ in hàng trăm!

// Test: Input 291
// a = 1 (đơn vị), b = 9 (chục), c = 2 (trăm)
// Swap a,b: a=9, b=1, c=2
// Output: 2 ❌ (Sai! Phải in vị trí của 9)

// ✅ ĐÚNG (Phải tìm vị trí của max):
int a=n%10, b=(n/10)%10, c=n/100;
int max_digit = max({a,b,c});
cout << "Vi tri chu so lon nhat: ";
if(c == max_digit) cout << "hang tram (" << c << ")";
if(b == max_digit) cout << "hang chuc (" << b << ")";
if(a == max_digit) cout << "hang don vi (" << a << ")";
```

---

### **4️⃣ Bài 12 - CRITICAL: Sai công thức chu vi + không check input**
```cpp
// ❌ N6 CODE (SAI):
cout<<"Chu vi hinh chu nhat la "<<(a+b)/2<<endl;  // ← SAI CÔNG THỨC!
// Công thức đúng: 2*(a+b), không phải (a+b)/2

// ❌ KHÔNG CHECK:
cin>>a; // ← Nhập canh âm/0 không check!
cout<<"Chu vi hinh vuong la "<<4*a;

// ✅ ĐÚNG:
if(a <= 0) {
    cout << "Canh phai > 0";
    return 0;
}
cout << "Chu vi hinh chu nhat la " << 2*(a+b);
```

---

### **5️⃣ Bài 13 - CRITICAL: KHÔNG HOÀN THÀNH, logic sai**
```cpp
// ❌ N6 CODE (SAI):
#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<0) return 0;
    else{
        if(n<1000) cout<<n*5000;  // ← SSSAI!!! Nếu n=0.5km sao tính?
        else if(n>1000&&n<1201) cout<<1000*5000+(n-200)*1000;  // ← Logic sai
        else if(n>1200) cout<<  // ← KHÔNG HOÀN THÀNH!
    }
    return 0;
}
// Test: Input 2 (km)
// Output: 2*5000 = 10000 ❌ (Sai! Phải là 5000 + (2-1)/0.2*1000)

// ✅ ĐÚNG:
if(n <= 1) {
    cout << 5000;  // Km đầu tiên
} else if(n <= 30) {
    cout << 5000 + (n-1)/0.2*1000;  // 200m tính 1000đ
} else {
    cout << 5000 + 29/0.2*1000 + (n-30)*3000;  // > 30km
}
```

---

### **6️⃣ Bài 14 - BUG LOGIC: Kiểm tra thừa (dư thừa)**
```cpp
// ❌ N6 CODE (SAI):
else if((a==b&&a==c)||(b==c&&b==a)){  // ← (b==c&&b==a) là lặp lại của (a==b&&a==c)
    
// ✅ ĐÚNG:
else if((a==b && b==c)) {  // Đơn giản hơn
    cout << "Tam giac deu";
} else if(a==b || b==c || a==c) {
    cout << "Tam giac can";
}
```

---

### **7️⃣ Bài 15 - THIẾU: Không check n <= 0**
```cpp
// ❌ N6 CODE (SAI):
int n;
cin>>n;
double k=sqrt(n);
if(k*k==n) cout<<"La so chinh phuong";
// Test: Input -4
// k = sqrt(-4) = NaN ← Kết quả không xác định!

// ✅ ĐÚNG:
if(n <= 0) {
    cout << "Vui long nhap so duong!";
    return 0;
}
double k=sqrt(n);
if(k*k==n) cout<<"La so chinh phuong";
```

---

## 📊 SO SÁNH N6 VỚI CÁC NHÓM KHÁC

### **Bài 9 - Kiểm tra ngày (năm nhuận):**

| Nhóm | Code | Edge Case |
|---|---|---|
| **N6** | Switch/case đầy đủ, check `y <= 0` | ✅ Tốt |
| **N7** | Đơn giản, check đầy đủ | ✅ Tốt |
| **N3** | Như N7 | ✅ Tốt |
| **N1** | Check cơ bản | ⭐⭐ |

### **Bài 12 - Diện tích hình:**

| Nhóm | Chu vi HCN | Check input | Tính Heron |
|---|---|---|---|
| **N6** | ❌ `(a+b)/2)` (SAI!) | ❌ KHÔNG | ✅ |
| **N7** | ✅ `2*(a+b)` | ⭐ Cơ bản | ✅ |
| **N3** | ✅ `2*(a+b)` | ⭐ Cơ bản | ✅ |
| **N1** | ✅ `2*(a+b)` | ⭐ Cơ bản | ✅ |

### **Bài 13 - Taxi:**

| Nhóm | Hoàn thành | Formula | Test |
|---|---|---|---|
| **N6** | ❌ KHÔNG | ❌ Sai | ❌ |
| **N7** | ✅ | ✅ Đúng | ✅ |
| **N3** | ✅ | ✅ Đúng | ✅ |
| **N2** | ✅ | ✅ Đúng | ✅ |

---

## 🎯 KẾT LUẬN & GỢI Ý LUYỆN TẬP

### **Nếu muốn luyện tập edge case:**

**Theo độ khó tăng dần:**
1. ✅ **N7/Bài 9** (Ngày hợp lệ) - Năm nhuận, ranh giới ngày/tháng
2. ✅ **N7/Bài 10** (Giờ hợp lệ) - Check [0-23], [0-59]
3. ✅ **N7/Bài 11** (Năm nhuận) - Formula modulo phức tạp
4. ✅ **N7/Bài 14** (Tam giác) - Kiểm tra tất cả loại tam giác + cạnh âm
5. ✅ **N7/Bài 13** (Taxi) - Ranh giới 1km, 30km, làm tròn 200m

---

### **Nếu muốn tìm bug để học:**

**Những bài N6 nên sửa:**
1. 🔴 **Bài 4** - Sửa: Thêm so sánh và in số lớn hơn
2. 🔴 **Bài 5** - Sửa: Thêm bước swap thứ 2
3. 🔴 **Bài 7** - Sửa: In vị trí của chữ số lớn nhất (không phải chỉ hàng trăm)
4. 🔴 **Bài 12** - Sửa: Công thức `2*(a+b)` + check input <= 0
5. 🔴 **Bài 13** - Sửa: Hoàn thành logic taxi
6. 🟡 **Bài 14** - Sửa: Đơn giản hóa logic check tam giác
7. 🟡 **Bài 15** - Sửa: Check n <= 0 trước khi tính sqrt

---

## ⭐ RANKING CUỐI CÙNG

| Xếp hạng | Nhóm | Điểm |
|---|---|---|
| 🥇 | **N7** | 95/100 |
| 🥈 | **N3** | 85/100 |
| 🥉 | **N1** | 75/100 |
| 4 | **N2** | 65/100 |
| 5 | **N4** | 60/100 |
| 6 | **N6** | 50/100 (nhiều bug) |
| 7 | **N5** | 40/100 |

