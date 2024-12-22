#include<stdio.h>
#include<string.h>

typedef struct {
	int id;
	char name[50];
	int age;
	char phoneNumber[15];
} SinhVien;

void xoaSv(int id, SinhVien sv[], int *currentLength) {
	int viTriXoa = -1;
	
	for(int i=0; i<*currentLength; i++) {
		if (sv[i].id == id) {
			viTriXoa = i;
			break;
		}
	}
	
	if (viTriXoa == -1) {
        printf("Sinh vien voi ID %d khong ton tai trong danh sach.\n", id);
        return;
    }
    
    for (int i=viTriXoa; i<*currentLength - 1; i++) {
    	sv[i] = sv[i+1];
	}
	
	(*currentLength)--;
	
	printf("Sinh vien voi ID %d da duoc xoa thanh cong.\n", id);
}

void inSv(const SinhVien sv[], int currentLength) {
	printf("Danh sach sinh vien hien tai:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n", 
               sv[i].id, sv[i].name, sv[i].age, sv[i].phoneNumber);
	}
}

int main() {
	#define MAX_SIZE 5 
    SinhVien sv[MAX_SIZE] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Tran Thi B", 21, "0987654321"},
        {3, "Le Van C", 22, "0111222333"},
        {4, "Pham Thi D", 23, "0999888777"},
        {5, "Hoang Van E", 24, "0888666555"}
    };
    
    int currentLength = MAX_SIZE;
    
    inSv(sv, currentLength);
    
    int viTriXoa;
    printf("\nNhap ID sinh vien can xoa: ");
    scanf("%d", &viTriXoa);
    xoaSv(viTriXoa, sv, &currentLength);
	
	printf("\nSau khi xoa:\n");
    inSv(sv, currentLength);
	
	return 0;
}

