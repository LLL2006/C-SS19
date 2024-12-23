#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void printStudents( struct Student s[], int currentLength) {
	printf("Danh sach sinh vien:\n");
	for(int i=0; i< currentLength; i++){
		printf("ID: %d, Ten: %s, Tuoi: %d, SÐT: %s\n", s[i].id, s[i].name, s[i].age, s[i].phoneNumber);
	}
}

void addStudent(struct Student s[], int *currentLength) {
	printf("Nhap ID sinh vien: ");
    scanf("%d", &s[*currentLength].id);
    printf("Nhap ten sinh virn: ");
    getchar();  
    fgets(s[*currentLength].name, 50, stdin);
    s[*currentLength].name[strcspn(s[*currentLength].name, "\n")] = '\0';
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &s[*currentLength].age);
    printf("Nhap so dien thoai sinh viên: ");
    getchar();  
    fgets(s[*currentLength].phoneNumber, 15, stdin);
    s[*currentLength].phoneNumber[strcspn(s[*currentLength].phoneNumber, "\n")] = '\0';  
    (*currentLength)++;
    printf("Sinh vien da duoc them thanh cong.\n");
}

void editStudent(struct Student s[], int currentLength) {
    int id;
    printf("Nhap ID sinh vien can sua: ");
    scanf("%d", &id);

    int found = -1;
    for (int i = 0; i < currentLength; i++) {
        if (s[i].id == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("Sua thong tin sinh vien %s:\n", s[found].name);
        printf("Nhap ten: ");
        getchar();
        fgets(s[found].name, 50, stdin);
        s[found].name[strcspn(s[found].name, "\n")] = '\0';
        printf("Nhap tuoi: ");
        scanf("%d", &s[found].age);
        printf("Nhap so dien thoai: ");
        getchar();
        fgets(s[found].phoneNumber, 15, stdin);
        s[found].phoneNumber[strcspn(s[found].phoneNumber, "\n")] = '\0'; 
        printf("Thong tin sinh vien da duoc sua thanh cong.\n");
    } else {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}

void deleteStudent(struct Student s[], int *currentLength) {
    int id;
    printf("Nhap ID sinh vien can xóa: ");
    scanf("%d", &id);

    int found = -1;
    for (int i = 0; i < *currentLength; i++) {
        if (s[i].id == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        for (int i = found; i < *currentLength - 1; i++) {
            s[i] = s[i + 1];
        }
        (*currentLength)--;
        printf("Sinh vien voi ID %d da duoc xoa\n", id);
    } else {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}

void searchStudent(struct Student s[], int currentLength) {
    int id;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &id);

    int found = -1;
    for (int i = 0; i < currentLength; i++) {
        if (s[i].id == id) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("Thong tin sinh vien tim thay:\n");
        printf("ID: %d, Ten: %s, Tuoi: %d, SÐT: %s\n", s[found].id, s[found].name, s[found].age, s[found].phoneNumber);
    } else {
        printf("Khong tim thay sinh vien voi ID %d.\n", id);
    }
}

void sortStudents(struct Student s[], int currentLength) {
    struct Student temp;
    for (int i = 0; i < currentLength - 1; i++) {
        for (int j = 0; j < currentLength - i - 1; j++) {
            if (strcmp(s[j].name, s[j + 1].name) > 0) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
    printf("Danh sach sinh vien da duoc sap xep theo tên.\n");
}

int main() {
    struct Student s[100];
    int currentLength = 0;
    int choice;

    do {
        printf("\nMENU:\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh viên\n");
        printf("7. Thoat\n");
        printf("Chon chuc nang (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printStudents(s, currentLength);
                break;
            case 2:
                addStudent(s, &currentLength);
                break;
            case 3:
                editStudent(s, currentLength);
                break;
            case 4:
                deleteStudent(s, &currentLength);
                break;
            case 5:
                searchStudent(s, currentLength);
                break;
            case 6:
                sortStudents(s, currentLength);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                return 0;
            default:
                printf("Vui long chon lai.\n");
        }
    } while (choice != 7);

    return 0;
}
