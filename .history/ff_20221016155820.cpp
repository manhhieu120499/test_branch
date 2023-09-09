#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ngay{
    int ngay, thang, nam;
};
struct SinhVien{
    char maSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};
struct Node{
    SinhVien data;
    Node* link;
};
struct List{
    Node *first;
    Node *last;
};
Node* getNode(SinhVien x);
void init(List &l);
void addLast(List &l, Node* p);
void insertLast(List &l, SinhVien x);
int nhapSV(SinhVien &x);
void nhapDSSV(List &l);
void xuatSV(SinhVien x);
void xuatDS(List l);


void menu();

int main(){
    List l;
    int chon = 0;
    do{
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &chon);
        switch(chon){
            case 1: 
                nhapDSSV(l);
                break;
            case 2:
                xuatDS(l);
                break;
        }
    }while(chon != 0);
}
void menu(){
    printf("\n----------------------------------\n");
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Xuat danh sach\n");
    printf("3. Ghi danh sach vao file\n");
    printf("4. Doc danh sach tu file\n");
    printf("5. Them sinh vien\n");
    printf("6. Xoa sinh vien\n");
    printf("7. Sap xep danh sach theo ten\n");
    printf("\n----------------------------------\n");
}
void inTieuDe(){
    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "Ma SV", "Ho Ten", "Ngay sinh",
        "Gioi Tinh", "Dia Chi", "Khoa", "Lop");
}
void xuatDS(List l){
    inTieuDe();
    Node* p = l.first;
    while(p){
        xuatSV(p->data);
        p=p->link;
    }
}
void xuatSV(SinhVien x){
    char gt[4];
    if(x.gioiTinh == 0)
        strcmp(gt, "Nam");
    else
        strcmp(gt, "Nu");
    printf("%-15s %-15s %15d/%d/%d %-15s %-15s %-15s %-15s\n", x.maSV, x.hoTen,
        x.ngaySinh.ngay, x.ngaySinh.thang, x.ngaySinh.nam, gt, 
        x.diaChi, x.khoa, x.lop);

}
void nhapDSSV(List &l){
    printf("Nhap danh sach sinh vien. Nhap ma sinh vien = 0 de dung\n");
    SinhVien x;
    int flag = nhapSV(x);
    while (flag){
        insertLast(l, x);
        flag = nhapSV(x);
    }
}
int nhapSV(SinhVien &x){
    int chon;
    fflush(stdin);
    printf("\nNhap ma sinh vien: ");  gets(x.maSV);
    if(strcmp(x.maSV, "0") == 0)
        return 0;
    printf("Nhap ho ten sinh vien: ");  gets(x.hoTen);
    printf("0. Nam\n");
    printf("1. Nu\n");
    printf("Chon gioi tinh: ");     scanf("%d", &chon);
    printf("Nhap ngay thang nam: ");
    scanf("%d %d %d", &x.ngaySinh.ngay, &x.ngaySinh.thang, &x.ngaySinh.nam);
    fflush(stdin);
    printf("Nhap dia chi: ");  
    fflush(stdin);
    gets(x.diaChi);
    printf("Nhap lop: ");   
    fflush(stdin);
    gets(x.lop);
    printf("Nhap khoa: "); 
     gets(x.khoa);
    return 1;
}
Node* getNode(SinhVien x){
    Node* p = new Node;
    if(p == NULL)
        return NULL;
    p->data = x;
    p->link = NULL;
    return p;
}
void init(List &l){
    l.first = l.last = NULL;
}
void addLast(List &l, Node* p){
    if(l.first == NULL)
        l.first = l.last  = p;
    else{
        l.last->link = p;
        l.last = p;
    }
}
void insertLast(List &l, SinhVien x){
    Node* p = getNode(x);
    if(p == NULL)
        printf("Khong them duoc !!!\n");
    else
        addLast(l, p);
}
