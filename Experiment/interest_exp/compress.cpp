#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <unordered_map>
using namespace std;

const size_t BufferSize = 128;
unsigned char buffer[129];
size_t count[257];
unordered_map<char, string> HFtable;
typedef struct HuffmanNode
{
    int weigh;
    char ch;
    HuffmanNode *left, *right;
} HuffmanNode;

class prioirtyQueue
{
private:
    // 内部由模拟二叉树的数组实现
    // 严格地，如果树的每个结点都大于等于它的孩子结点，称为最大堆，反之为最小堆。
    // 我们可以取树的根节点，然后再每次插入或删除操作时重新调整二叉树的结构

    HuffmanNode **heap;
    int size;

    void swapNode(int t, int u)
    {
        HuffmanNode *tmp = heap[t];
        heap[t] = heap[u];
        heap[u] = tmp;
    }
    //  向下调整节点
    void down(int u)
    {
        // t用于暂存u的值
        int t = u;
        // 取三个节点中的最小值
        if (2 * t <= this->size && heap[t]->weigh > heap[2 * t]->weigh)
            u = 2 * t;
        if (2 * t + 1 <= this->size && heap[u]->weigh > heap[2 * t + 1]->weigh)
            u = 2 * t + 1;
        if (u != t)
        {
            swapNode(u, t);
            down(u);
        }
    }

    void up(int u)
    {
        while (u / 2 && heap[u / 2]->weigh > heap[u]->weigh)
        {
            swapNode(u, u / 2);
            u >>= 1;
        }
    }

public:
    prioirtyQueue()
    {
        size = 0;
        heap = (HuffmanNode **)malloc(sizeof(HuffmanNode *) * 257);
    };
    ~prioirtyQueue()
    {
        for (size_t i = 0; i < 257; i++)
            free(heap[i]);
    };

    HuffmanNode *top()
    {
        return heap[1];
    }

    int num()
    {
        return this->size;
    }

    void insert(HuffmanNode *newNode)
    {
        heap[++size] = newNode;
        up(size);
    }

    HuffmanNode *removeTop()
    {
        HuffmanNode *ret = heap[1];
        heap[1] = heap[size--];
        down(1);
        return ret;
    }
};

prioirtyQueue HFQueue;

bool isLeafNode(HuffmanNode *node)
{
    if (node == NULL)
        return false;
    if (node->left == NULL && node->right == NULL)
        return true;
    return false;
}
// 中心思想：我们可以通过遍历查询编码树中权值最小的节点
// 但为了性能优化，我们采用小根堆模拟优先队列的实现
// 实现插入任意一个数，查询最小值，删除最小值

HuffmanNode *createLeafNode(int index)
{
    HuffmanNode *newNode = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    newNode->weigh = count[index];
    newNode->ch = (char)index;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

HuffmanNode *createTopNode(HuffmanNode *min, HuffmanNode *secondMin)
{
    HuffmanNode *parentNode = (HuffmanNode *)malloc(sizeof(HuffmanNode));
    // 选择一个不会被误判的超字符，如文件结束符
    parentNode->ch = 0;
    parentNode->weigh = min->weigh + secondMin->weigh;
    parentNode->left = min;
    parentNode->right = secondMin;
    return parentNode;
}

// 传递一个指针的引用

void initHuffmanTree(HuffmanNode *&root, prioirtyQueue &HFQueue)
{
    // 朴素建堆 O(n*logn)的复杂度
    for (size_t i = 0; i < 257; i++)
        if (count[i])
            HFQueue.insert(createLeafNode(i));
    while (HFQueue.num() > 1)
    {
        HuffmanNode *a = HFQueue.removeTop();
        HuffmanNode *b = HFQueue.removeTop();
        root = createTopNode(a, b);
        HFQueue.insert(root);
    }
}

void countWeigh(unsigned char buffer[])
{
    FILE *file;
    memset(count, 0, sizeof(count));
    size_t bytesRead;
    file = fopen("simple.txt", "rb");
    if (file == NULL)
    {
        // 输出错误输入对应的指定前缀字符串
        perror("Error opening the file");
    }
    // 对应不同的ASCII码的目的
    /*elementSize 以字节为单位*/
    while ((bytesRead = fread(buffer, 1, BufferSize, file)) > 0)
    {
        // 统计不同字符的数量
        for (size_t i = 0; i < BufferSize; i++)
        {
            if (buffer[i] != EOF && buffer[i] != '\0')
            {
                count[buffer[i]]++;
            }
            else
            {
                puts("The file has been read completely...");
                fclose(file);
                return;
            }
        }
        // 重新置零
        memset(buffer, 0, sizeof(*buffer));
    }
}
// 这应当成为一个私有的编码表构建的helper，即不被外界函数所调用的
// void generateTable(std::unordered_map<char, std::string> HFtable, std::string str, HuffmanNode *root)
// {
//     if (isLeafNode(root))
//     {
//         // 函数参数需要一个pair键值对
//         HFtable.insert({root->ch, str});
//     }
//     else
//     {
//         generateTable(HFtable, str + "0", root->left);
//         generateTable(HFtable, str + "1", root->right);
//     }
// }

// void constructHFTable(HuffmanNode *root)
// {
//     // 树高不宜过深
//     std::string str;
//     // 什么遍历方式可以构建这张表？？？
//     // 答：除了层序遍历的任何一种深度优先遍历都是可以的
//     // 这里实现编码树的preorder
//     generateTable(HFtable, str, root);
// }

int main()
{
    countWeigh(buffer);
    for (size_t i = 0; i < 257; i++)
    {
        if (count[i])
        {
            printf("%c 出现了 %d次\n", (char)i, count[i]);
        }
    }
    HFtable.insert({'1', "das"});
    HuffmanNode *root;

    initHuffmanTree(root, HFQueue);

    /*方法一：hashtable实现，可在常数实现内查询，同时占用更多的内存空间
     方法二：查找树：查找复杂度取决于树高，但便于频繁的修改*/
    // constructHFTable(root);
    system("pause");
    return 0;
}