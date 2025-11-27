#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

Node* newNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* buildTree(char* pre, char* in, int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    char rootData = pre[(*preIndex)++];
    Node* root = newNode(rootData);

    if (inStart == inEnd)
        return root;

    int inIndex;
    for (inIndex = inStart; inIndex <= inEnd; inIndex++) {
        if (in[inIndex] == rootData)
            break;
    }

    root->left = buildTree(pre, in, inStart, inIndex - 1, preIndex);
    root->right = buildTree(pre, in, inIndex + 1, inEnd, preIndex);

    return root;
}

void postOrder(Node* root) {
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%c", root->data);
}

int main() {
    int C;
    scanf("%d", &C); 

    while (C--) {
        int N;
        char pre[53], in[53]; 

        scanf("%d %s %s", &N, pre, in);

        int preIndex = 0;
        Node* root = buildTree(pre, in, 0, N - 1, &preIndex);

        postOrder(root);
        printf("\n");
    }

    return 0;
}