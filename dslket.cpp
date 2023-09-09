#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Ngay
{
    int ngay, thang, nam;
};

struct SinhVien
{
    char mSSV[9];
    char hoTen[25];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[15];
    char khoa[10];
};

struct Node
{
    SinhVien data;
    Node* pLink;
};

struct List
{
    Node* head;
    Node* tail;
};

void Init(List &l);
Node* getNode(SinhVien x);
void addTail(List &l, Node* p);
Node* searchMaSV(List &l, char ma[9]);
void inputSinhVien(List &l, SinhVien &x);
void nhapDSLK(List &l);
void outputSinhVien(SinhVien x);
void xuatDSLK(List l);


int main() {


    return 0;
}

void Init(List &l) {
    l.head = l.tail = NULL;
}

Node* getNode(SinhVien x) {
    Node* p = new Node;
    if(p == NULL) return NULL;
    else {
        p->data = x;
        p->pLink = NULL;
    }
    return p;
}

void addTail(List &l, Node* p) {
    if(l.head == NULL) {
        l.head = l.tail = NULL;
    }else {
        l.tail->pLink = p;
        l.tail = p;
    }
}

Node* searchMaSV(List &l, char ma[9]) {
    Node* p = l.head;
    while(p != NULL) {
        if(strcmp(p->data.mSSV, ma) == 0) {
                return p;
        }
        p = p->pLink;
    }
    return  NULL;
}

void inputSinhVien(List &l , SinhVien &x) {
    int flag = 0;
    do{
        printf("nhap vao ma so sinh vien: ");
        fflush(stdin);
        gets(x.mSSV);
        if(searchMaSV(l,x.mSSV) != NULL){
              printf("Ma sinh vien da ton tai. Yeu cau nhap lai\n");
              flag++;
        }   
    }while(flag == 1);
    
    printf("nhap vao ho ten sinh vien: ");
    fflush(stdin);
    gets(x.hoTen);
    printf("nhap vao gioi tinh sinh vien (0. nam / 1. nu): ");
    fflush(stdin);
    scanf("%d", &x.gioiTinh);
    printf("nhap vao ngay sinh cua sinh vien: ");
    scanf("%d/%d/%d", &x.ngaySinh.ngay, &x.ngaySinh.thang, &x.ngaySinh.nam);
    printf("nhap vao dia chi cua sinh vien: ");
    fflush(stdin);
    gets(x.diaChi);
    printf("nhap vao lop cua sinh vien: ");
    fflush(stdin);
    gets(x.lop);
    printf("nhap vao khoa cua sinh vien: ");
    fflush(stdin);
    gets(x.khoa);
}

void nhapDSLK(List &l) {
    int n;
    SinhVien x;
    do{
        printf("nhap vao so luong sinh vien (n > 0): ");
        scanf("%d",&n);
    }while(n <= 0);

    for(int i = 0 ; i < n ; i++) {
        printf("nhap vao thong tin cua sinh vien thu %d\n", i + 1);
        inputSinhVien(l,x);
        Node* newNode = getNode(x);
        addTail(l,newNode);
    }
    printf("ket thuc nhap danh sach\n");
}

void outputSinhVien(SinhVien x) {
    char gt[4], ns[20], tam[10];
    if(x.gioiTinh == 0) {
        strcpy(gt,"Nam");
    }else {
        strcpy(gt, "Nu");
    }
    itoa(x.ngaySinh.ngay, tam, 10);
    strcpy(ns, tam);
    itoa(x.ngaySinh.thang, tam, 10);
    strcat(ns, "/");
    strcat(ns, tam);
    itoa(x.ngaySinh.nam, tam, 10);
    strcat(ns, "/");
    strcat(ns, tam);

    printf("|%-9s |%-40s |%-10s |%-15s |%-30s |%-10s |%-8s|\n", x.mSSV,x.hoTen,gt,ns,x.diaChi,x.lop,x.khoa);
}


void xuatDSLK(List l) {
    if(l.head != NULL) {
        // inTieuDeCot();
        for(Node* p = l.head ; p!= NULL ; p = p->pLink) {
            outputSinhVien(p->data);
        }
    }else {
        printf("Danh sach rong\n");
    }
}



