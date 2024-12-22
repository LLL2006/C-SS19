#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

void sapXep(struct Student students[], int size) {
    struct Student temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void printStudents(struct Student students[], int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    struct Student students[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Tran Thi B", 22, "0987654321"},
        {3, "Le Van C", 21, "0111222333"},
        {4, "Pham Thi D", 23, "0999888777"},
        {5, "Hoang Van E", 20, "0888666555"}
    };

    printf("Truoc khi sap xep:\n");
    printStudents(students, 5);

    sapXep(students, 5);

    printf("\nSau khi sap xep:\n");
    printStudents(students, 5);

    return 0;
}
