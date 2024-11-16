#define MAX 100
typedef int Data;
struct tagNode {
    Data infor;
    tagNode* pNext;
};
typedef tagNode NODE;
struct List
{
    NODE* Head;
    NODE* Tail;
};
//=================================================
NODE* GetNode(Data x);
void TaoDS(List& a);
int KTDS(List a);
void InsertTail(List& a, Data x);
int DocFile(char* filename, List& a);
void XuatDS(List a);
NODE* Search_YN(List a, Data x);
NODE* Search_x_First(List a, Data x);
int Search_First(List a, Data x);
NODE* Search_Last(List a, Data x);
int Search_VTLast(List a, Data x);
void Search_VTAll(List a, Data x);
void AddFirst(List& a, NODE* new_ele);
void AddTail(List& a, NODE* new_ele);
void InsertFirst(List& a, Data x);
void InsertAfter(List& a, NODE* y, Data x);
void InsertX_First_Y(List& a, Data y, Data x);
void RemoveHead(List& a);
void RemoveTail(List& a);
int RemoveNode_First(List& a, Data x);
//=================================================
NODE* GetNode(Data x)
{
    NODE* vt;
    vt = new NODE;
    if (vt != NULL)
    {
        vt->infor = x;
        vt->pNext = NULL;
    }
    return vt;
}
void TaoDS(List& a)
{
    a.Head = a.Tail = NULL;
}
int KTDS(List a)
{
    if (a.Head == NULL)
        return 1;
    return 0;
}
int DocFile(char* filename, List& a)
{
    ifstream in(filename);
    if (!in)
        return 0;
    TaoDS(a);
    Data x;
    while (!in.eof())
    {
        in >> x;
        InsertTail(a, x);
    }
    in.close();
    return 1;
}
void XuatDS(List a)
{
    NODE* vt;
    if (KTDS(a))
    {
        cout << "\nDanh sach rong";
        return;
    }
    vt = a.Head;
    while (vt != NULL)
    {
        cout << vt->infor << "\t";
        vt = vt->pNext;
    }
}
void InsertTail(List& a, Data x)
{
    NODE* new_ele = GetNode(x);
    if (new_ele == NULL)
    {
        cout << "\nLoi cap phat bo nho";
        return;
    }
    if (a.Head == NULL)
    {
        a.Head = new_ele;
        a.Tail = a.Head;
    }
    else
    {
        a.Tail->pNext = new_ele;
        a.Tail = new_ele;
    }
}
NODE* Search_YN(List a, Data x)
{
    NODE* vt;
    vt = a.Head;
    while ((vt != NULL) && (vt->infor != x))
    {
        vt = vt->pNext;
    }
    return vt;
}
NODE* Search_x_First(List a, Data x)
{
    NODE* vt;
    vt = a.Head;
    while ((vt != NULL) && (vt->infor != x))
    {
        vt = vt->pNext;
    }
    return vt;
}
int Search_First(List a, Data x)
{
    NODE* vt;
    int i = 0;
    vt = a.Head;
    while ((vt != NULL) && (vt->infor != x))
    {
        vt = vt->pNext;
        i++;
    }
    if (vt == NULL)
        i = -1;
    return i;
}
NODE* Search_Last(List a, Data x)
{
    NODE* p, * q = NULL;
    p = a.Head;
    while (p != NULL)
    {
        if (p->infor == x)
            q = p;
        p = p->pNext;
    }
    return q;
}
int Search_VTLast(List a, Data x)
{
    NODE* p;
    int kq = -1, i = 0;
    p = a.Head;
    while (p != NULL)
    {
        if (p->infor == x)
            kq = i;
        i++;
        p = p->pNext;
    }
    return kq;
}
void Search_VTAll(List a, Data x)
{
    NODE* p = Search_x_First(a, x);
    int i = 0;
    if (p == NULL)
    {
        cout << x << " khong co trong danh sach";
        return;
    }
    cout << x << " xuat hien tai cac vi tri\n";
    p = a.Head;
    while (p != NULL)
    {
        if (p->infor == x)
            cout << i << "\t";
        p = p->pNext;
        i++;
    }
}
void AddFirst(List& a, NODE* new_ele)
{
    if (a.Head == NULL)
    {
        a.Head = new_ele;
        a.Tail = a.Head;
    }
    else
    {
        new_ele->pNext = a.Head;
        a.Head = new_ele;
    }
}
void InsertFirst(List& a, Data x)
{
    NODE* new_ele = GetNode(x);
    if (new_ele == NULL)
    {
        cout << "\nLoi cap phat bo nho";
        return;
    }
    if (a.Head == NULL)
    {
        a.Head = new_ele;
        a.Tail = a.Head;
    }
    else
    {
        new_ele->pNext = a.Head;
        a.Head = new_ele;
    }
}
void AddTail(List& a, NODE* new_ele)
{
    if (KTDS(a))
    {
        a.Head = new_ele;
        a.Tail = a.Tail;
    }
    else
    {
        a.Tail->pNext = new_ele;
        a.Tail = new_ele;
    }
}
void InsertAfter(List& a, NODE* y, Data x)
{
    NODE* new_ele = GetNode(x);
    if (new_ele == NULL)
    {
        cout << "\nLoi cap phat bo nho";
        return;
    }
    if (y != NULL)
    {
        new_ele->pNext = y->pNext;
        y->pNext = new_ele;
        if (y == a.Tail)
            a.Tail = new_ele;
    }
    else
        AddFirst(a, new_ele);
}
void InsertX_First_Y(List& a, Data y, Data x)
{
    NODE* q;
    q = Search_x_First(a, y);
    InsertAfter(a, q, x);
}
void InsertX_End_Y(List& a, Data y, Data x)
{
    NODE* q;
    q = Search_Last(a, y);
    InsertAfter(a, q, x);
}
void RemoveHead(List& a)
{
    NODE* p;
    if (a.Head == NULL)
    {
        cout << "\n Danh sach rong. Khong the xoa";
        return;
    }
    p = a.Head;
    a.Head = a.Head->pNext;
    delete(p);
    if (a.Head == NULL)
        a.Tail = NULL;
}
void RemoveTail(List& a)
{
    NODE* p, * q;
    if (a.Head == NULL)
    {
        cout << "\nDanh sach rong. Khong the xoa";
        return;
    }
    p = a.Head;
    q = NULL;
    while (p != a.Tail)
    {
        q = p;
        p = p->pNext;
    }
    a.Tail = q;
    delete(p);
    if (a.Tail == NULL)
        a.Head = NULL;
    else
        a.Tail->pNext = NULL;
}
int RemoveNode_First(List& a, Data x)
{
    NODE* p = a.Head, * q = NULL;
    while (p != NULL)
    {
        if (p->infor == x)
            break;
        q = p;
        p = p->pNext;
    }
    if (p == NULL)
        return 0;
    if (q != NULL)
    {
        if (p == a.Tail)
            a.Tail = q;
        q->pNext = p->pNext;
    }
    else
    {
        a.Head = p->pNext;
        if (a.Head == NULL)
            a.Tail = NULL;
    }
    delete(p);
    return 1;
}