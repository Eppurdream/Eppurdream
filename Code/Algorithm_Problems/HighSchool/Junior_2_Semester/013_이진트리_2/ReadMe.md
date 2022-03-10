```
    1. 완전 이진 트리
    - 완전 이진 트리의 각 노드는 계측적인 구조로 이루어져 있다. 루트 노드의 레벨은 0이며, 레벨 1의 두 자식 노드를 가지고 있다. 또, 레벨 1의 자식 노드의 레벨은 2이다. 보통 레벨이 N인 완전 이진 트리는 2^N-1 개의 노드를 가지고 있다. 레벨이 N-1이 아닌 모든 노드는 자식 노드를 두 개씩 가지고 있다. 1부터 2^N-1 까지 숫자를 레벨이 n인 완전 이진 트리의 각 노드에 적을 수 있다. 이때, 레벨이 D인 각각의 노드에 대해서 왼쪽 서브트리에 쓰여 있는 숫자의 합과 오른쪽 서브트리에 쓰여 있는 숫자의 합의 차이는 2^D 라는 조건을 만족해야 한다.
    예를 들어, 루트의 왼쪽 서브트리의 합과 오른쪽 서브 트리의 합의 차이는 1이어야 하며, 레벨이 1인 경우에는 2이어야 한다. 또, 모든 숫자는 한 번씩 사용해야 한다. N이 주어졌을 때, 문제의 조건에 맞게 완전 이진 트리의 각 노드에 숫자를 정하는 프로그램을 작성하시오.
```

- 풀이 코드

```cpp
    #include <iostream>
    using namespace std;

    void preorder(int rootNode, int level);
    int square(int i, int count);

    int level = 0;

    int main()
    {
        cin >> level;
        if (level < 0)
        {
            cout << "level은 양수여야 합니다 " << endl;
            return 0;
        }

        int rootNode = square(2, level) - 1;
        cout << rootNode << " ";
        preorder(rootNode, 1);
        return 0;
    }

    void preorder(int rootNode, int i)
    {
        if (i + 1 == level) 
        {
            cout << (square(2, level - 1) + 1) - (rootNode - i) << " ";
            cout << (square(2, level - 1) + 1) - (rootNode - (i * 2)) << " ";
            return;
        }
        int leftNode = rootNode - i;
        cout << leftNode << " ";
        preorder(leftNode, i + 1);
        int rightNode = leftNode - i;
        cout << rightNode << " ";
        preorder(rightNode, i + 1);
    }

    int square(int i, int count)
    {
        int temp = i;
        for (int n = 0; n < count - 1; n++)
        {
            temp *= i;
        }
        return temp;
    }
```

- 루트 노드를 기준으로 왼쪽 자식노드들과 오른쪽 자식노드들의 합의 차이가 1만 나게 하는 코드이다.
- 지금 코드를 보았을 때 어떤 방식으로 구현이 되었는지는 알지 못하지만 이때 당시 코드를 완성하기 위해서 화이트 보드에 경우의 수를 50번 넘게 계산한 기억이 있다.