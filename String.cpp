#pragma once 
#include "String.h"

void String::output(ostream& out) const
{
	//out << "num=" << num<<endl;
	for (int i = 0; i < num; i++) {
		out << this->elems[i];
	}
}

void String::input(istream& in)
{
	string s;
	in >> s;
	*this = s.c_str();
}

String String::operator+(String& str)
{
	int i, j;
	String add;
	add.__super::num = __super::num + str.__super::num;
	add.elems = new char[add.__super::num+10];
	for (i = 0; i < __super::num; i++)
	{
		add.elems[i] = elems[i];
	}
	for (j = 0; j < str.__super::num; j++)
	{
		add.elems[i + j] = str.elems[j];
	}
	add._size = add.num+2;
	return add;

}

int String::size()
{
	return this->num;
}

ostream& operator<<(ostream& out, String& str)
{
	str.output(out);
	return out;
}

istream& operator>>(istream& in, String& str)
{
	str.input(in);
	return in;
}

bool String::operator==(const String& s) const {
    if (strCmp(*this, s) == 1) return 1;
    else return 0;
}
bool String::operator==(const char* s) const {
    String tmp(s);
    if (strCmp(*this, tmp) == 1) return 1;
    else return 0;
}
//����ΪAC�Զ�������

const int MAXN = 10001;
// ����Ŀ���ַ��������ַ�����
const int MAXS = 10001;

// ��¼ÿ���ڵ��Ƿ񱨾�
bool alert[MAXS];
// ÿ���ڵ��¼��Ƶ
int times[MAXS];
// ��¼ÿ��Ŀ�괮�Ľ�β�ڵ���
int en[MAXN];

int tree[MAXS][58];
int fail[MAXS];
int cnt = 0;

// �����������л���ջ��һ����������
int box[MAXS];

// ��ʽǰ���ǣ�Ϊ�˽���failָ��ķ�ͼ
int head[MAXS];
int Next[MAXS];
int to[MAXS];
int edge = 0;

String s;
int path;
int n;

void ACclean() {
    edge = 0;
    for (int i = 1; i <= n; i++) {
        en[i] = 0;
    }
    for (int i = 0; i <= cnt; i++) {
        fail[i] = 0;
        times[i] = 0;
        alert[i] = false;
        head[i] = 0;
        for (int j = 0; j < 58; j++) {
            tree[i][j] = 0;
        }
    }
    cnt = 0;
}

void addEdge(int u, int v) {
    Next[++edge] = head[u];
    head[u] = edge;
    to[edge] = v;
}//��Ƶͳ��

void f1(int u) {
    for (int i = head[u]; i > 0; i = Next[i]) {
        f1(to[i]);
        times[u] += times[to[i]];
    }
}//��Ƶͳ��

void insert(int i, String word) {
    //i��Ŀ�괮�ı��
    int cur = 0;//ͷ�������Ϊ0
    for (int i = 0; i < word.size(); i++) {
        char ch = word[i];
        path = ch - 'A';
        if (tree[cur][path] == 0) {
            tree[cur][path] = ++cnt;
            //û��·��Ҫ�½�һ��·  ��������
        }
        cur = tree[cur][path];
    }
    alert[cur] = true;
    en[i] = cur;
}
void setFail() {
    // box����������ʹ��
    int l = 0;
    int r = 0;
    for (int i = 0; i <= 57; i++) {
        if (tree[0][i] > 0) {
            box[r++] = tree[0][i];
            //0�ڵ���ֻ���к��ӵĽڵ���������
            //�����������洢�������нڵ㶼Ҫ��fail
        }
    }
    while (l < r) {
        int u = box[l++];
        for (int i = 0; i <= 57; i++) {
            if (tree[u][i] == 0) {
                tree[u][i] = tree[fail[u]][i];
            }
            else {
                fail[tree[u][i]] = tree[fail[u]][i];//����������ӽڵ��failָ��   ֱͨ���������ƻ�
                box[r++] = tree[u][i];//��ʾ������֧·  ���뵽������
            }
        }
        // ���б��ǰ��
        alert[u] |= alert[fail[u]];
    }
}
void ACauto()
{
    cout << "������ؼ�������: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "������� " << i << " ���ؼ���: ";
        String str;
        cin >> str;
        insert(i, str);
    }
    setFail();
    cout << "����������ַ���: ";
    cin >> s;
    cout << endl << endl;
    if (1) {
        cout << "�ؼ��ʱ�������" << endl;
        int u = 0, k = 0, f = 0;//f�����ж��Ƿ�������
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (alert[u]) {
                cout << "�ڵ� " << k << " ��λ�ô����ؼ��ʣ�" << endl << endl;
                f = 1;
                break;
            }
            k++;
            u = tree[u][ch - 'A'];//��ʾ������һ���ڵ�
        }
        if (f == 0)
            cout << "����������δ�����κ����⡣" << endl << endl;
    }
    if (1) {
        cout << "��Ƶͳ�ƹ���" << endl;
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            u = tree[u][ch - 'A'];//��ʾ������һ���ڵ�
            // ����ƥ�����
            times[u]++;
        }
        for (int i = 1; i <= cnt; i++) {
            // ����failָ�뽨��ͼ
            // ��ʵ��һ����
            addEdge(fail[i], i);
        }
        // ����failָ�뽨����
        // ����ÿ���ڵ�Ĵ�Ƶ
        f1(0);
        for (int i = 1; i <= n; i++) {
            cout << "�� " << i << " ���ؼ��ʳ����� " << times[en[i]] << " ��" << endl;
        }
        cout << endl;
    }
    //����if�������Ϊ����ͬ�ľֲ�����  ��ò�Ҫ��
    ACclean();
}
//Manacher
char ss[MAXN << 1];//��������м������#
String a;//ԭʼ����
int p[MAXN << 1];//�뾶����
int maxans, maxend;

void manacherss() {
    n = a.size() * 2 + 1;
    for (int i = 0, j = 0; i < n; i++) {
        ss[i] = (i & 1) == 0 ? '#' : a[j++];
        //cout << ss[i] << ' ';
    }
    //cout << endl;
}

void manacher() {
    manacherss();
    maxans = 0;
    for (int i = 0, c = 0, r = 0, len; i < n; i++) {//i�Ǵ�ʱ����������λ��
        len = r > i ? min(p[2 * c - i], r - i) : 1;//���ֵ�ǻ���ֵ  �����ס��  ��ô����ֵ��������ֵ  ��������ټ�
        while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len]) {
            len++;
            //�������ס��  ��ôֱ����������
        }
        //��ʱ�Ѿ��������iΪ���ĵĻ��İ뾶��С
        if (i + len > r) {
            r = i + len;
            c = i;
            //����������ұ߽�  ��ôc����i  r����i+len
        }
        if (len > maxans) {
            maxans = len - 1;//������ȱ���Ҫ��1
            maxend = (i + len - 1) / 2;//������Ӵ�ʵ�ʵĽ���λ��(���ܵ���)
        }
        p[i] = len;
        //�õ����İ뾶
    }
}

void Manacher()
{
    cout << "�������ַ����� ";
    cin >> a;
    /*for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }*/
    cout << endl;
    manacher();
    cout << "���������Ӵ���" << endl;
    for (int i = maxend - maxans; i < maxend; i++) {
        cout << a[i];
    }
    cout << endl << endl;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += p[i] / 2;//p[i]/2��ʾ��iΪ���ĵĻ��Ĵ�����
    }
    cout << "����ַ����Ļ����Ӵ�һ���� " << ans << " ��" << endl;
}


bool strCmp(String a, String b)
{
    int sz = a.num;
    for (int i = 0; i < sz; i++) {
        if (a.elems[i] != b.elems[i]) return 0;
    }
    return 1;
}