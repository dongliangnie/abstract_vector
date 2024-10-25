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
//以下为AC自动机功能

const int MAXN = 10001;
// 所有目标字符串的总字符数量
const int MAXS = 10001;

// 记录每个节点是否报警
bool alert[MAXS];
// 每个节点记录词频
int times[MAXS];
// 记录每个目标串的结尾节点编号
int en[MAXN];

int tree[MAXS][58];
int fail[MAXS];
int cnt = 0;

// 可以用作队列或者栈，一个容器而已
int box[MAXS];

// 链式前向星，为了建立fail指针的反图
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
}//词频统计

void f1(int u) {
    for (int i = head[u]; i > 0; i = Next[i]) {
        f1(to[i]);
        times[u] += times[to[i]];
    }
}//词频统计

void insert(int i, String word) {
    //i是目标串的编号
    int cur = 0;//头结点设置为0
    for (int i = 0; i < word.size(); i++) {
        char ch = word[i];
        path = ch - 'A';
        if (tree[cur][path] == 0) {
            tree[cur][path] = ++cnt;
            //没有路就要新建一条路  并赋予编号
        }
        cur = tree[cur][path];
    }
    alert[cur] = true;
    en[i] = cur;
}
void setFail() {
    // box当做队列来使用
    int l = 0;
    int r = 0;
    for (int i = 0; i <= 57; i++) {
        if (tree[0][i] > 0) {
            box[r++] = tree[0][i];
            //0节点中只有有孩子的节点加入队列中
            //这个队列里面存储过的所有节点都要有fail
        }
    }
    while (l < r) {
        int u = box[l++];
        for (int i = 0; i <= 57; i++) {
            if (tree[u][i] == 0) {
                tree[u][i] = tree[fail[u]][i];
            }
            else {
                fail[tree[u][i]] = tree[fail[u]][i];//设置这个孩子节点的fail指针   直通表辅助不用绕环
                box[r++] = tree[u][i];//表示有这条支路  加入到队列中
            }
        }
        // 命中标记前移
        alert[u] |= alert[fail[u]];
    }
}
void ACauto()
{
    cout << "请输入关键词数量: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "请输入第 " << i << " 个关键词: ";
        String str;
        cin >> str;
        insert(i, str);
    }
    setFail();
    cout << "请输入待测字符串: ";
    cin >> s;
    cout << endl << endl;
    if (1) {
        cout << "关键词报警功能" << endl;
        int u = 0, k = 0, f = 0;//f用于判断是否有问题
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (alert[u]) {
                cout << "在第 " << k << " 个位置触发关键词！" << endl << endl;
                f = 1;
                break;
            }
            k++;
            u = tree[u][ch - 'A'];//表示到达下一个节点
        }
        if (f == 0)
            cout << "输入正常，未引发任何问题。" << endl << endl;
    }
    if (1) {
        cout << "词频统计功能" << endl;
        int u = 0;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            u = tree[u][ch - 'A'];//表示到达下一个节点
            // 增加匹配次数
            times[u]++;
        }
        for (int i = 1; i <= cnt; i++) {
            // 根据fail指针建反图
            // 其实是一颗树
            addEdge(fail[i], i);
        }
        // 遍历fail指针建的树
        // 汇总每个节点的词频
        f1(0);
        for (int i = 1; i <= n; i++) {
            cout << "第 " << i << " 个关键词出现了 " << times[en[i]] << " 次" << endl;
        }
        cout << endl;
    }
    //两个if语句是因为有相同的局部变量  最好不要改
    ACclean();
}
//Manacher
char ss[MAXN << 1];//这个数组中间添加了#
String a;//原始数组
int p[MAXN << 1];//半径数组
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
    for (int i = 0, c = 0, r = 0, len; i < n; i++) {//i是此时来到的中心位置
        len = r > i ? min(p[2 * c - i], r - i) : 1;//这个值是基本值  如果包住了  那么基本值就是最终值  否则后续再加
        while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len]) {
            len++;
            //如果被包住了  那么直接跳出来了
        }
        //此时已经求出了以i为中心的回文半径大小
        if (i + len > r) {
            r = i + len;
            c = i;
            //如果更新了右边界  那么c就是i  r就是i+len
        }
        if (len > maxans) {
            maxans = len - 1;//这个长度必须要减1
            maxend = (i + len - 1) / 2;//最长回文子串实际的结束位置(不能到达)
        }
        p[i] = len;
        //得到回文半径
    }
}

void Manacher()
{
    cout << "请输入字符串： ";
    cin >> a;
    /*for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }*/
    cout << endl;
    manacher();
    cout << "输出最长回文子串：" << endl;
    for (int i = maxend - maxans; i < maxend; i++) {
        cout << a[i];
    }
    cout << endl << endl;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += p[i] / 2;//p[i]/2表示以i为中心的回文串数量
    }
    cout << "这个字符串的回文子串一共有 " << ans << " 个" << endl;
}


bool strCmp(String a, String b)
{
    int sz = a.num;
    for (int i = 0; i < sz; i++) {
        if (a.elems[i] != b.elems[i]) return 0;
    }
    return 1;
}