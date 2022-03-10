```
    1-1. 큐 구현하기
    - 선형 큐를 만들어 주요 연산인 삽입 연산과 삭제 연산을 구현하시오.
    1-2. 큐의 삽입/삭제
    - 선형 큐에 자료를 직접 삽입, 삭제 해보고 큐의 다양한 상황(꽉 찬 경우, 빈 경우)을 구현하시오.
    1-3. 원형 큐 실습
    - 논리적으로 Rear포인터나 Front포인터가 배열의 끝에 도달하면 회전하도록 만들어 원형 큐를 구현하시오.
```

- 풀이 코드

```cpp
    // 1-1번 문제

    #include <iostream>
    using namespace std;
    
    template<typename T>
    class queue {
    private:
        T* arr;
        int isize;
        int maxSize;
        bool isConstSize;
    public:
        queue();
        ~queue();
        void push(T t);
        void pop();
        T front();
        T rear();
        int size();
        void fmaxSize(T t);
    };
    
    template<typename T>
    queue<T>::queue()
    {
        arr = (T*)malloc(0);
        isize = 0;
        maxSize = 0;
        isConstSize = false;
    }
    
    template<typename T>
    queue<T>::~queue()
    {
        free(arr);
    }
    
    template<typename T>
    void queue<T>::push(T t)
    {
        if (isConstSize)
        {
            if (maxSize <= isize)
            {
                cout << "크기를 초과하셨서요.." << "maxSize : " << maxSize << endl;
                return;
            }
        }
        if (maxSize > isize)
        {
            arr[isize] = t;
            isize++;
            return;
        }
        void* temp = realloc(arr, sizeof(T) * (isize + 1));
        if (temp == NULL)
        {
            return;
        }
        arr = (T*)temp;
        arr[isize] = t;
        isize++;
        maxSize = isize;
    }
    
    template<typename T>
    void queue<T>::pop()
    {
        if (isize == 0)
        {
            cout << "안에 든게 더 이상 없어요" << endl;
            throw out_of_range("size가 0 이에요.");
            return;
        }
        for (int i = 0; i < isize; i++)
        {
            arr[i] = arr[i + 1];
        }
        isize--;
    }
    
    template<typename T>
    T queue<T>::front()
    {
        if (isize == 0)
        {
            throw out_of_range("size를 초과한 연산입니다."); 
        }
        return arr[0];
    }
    
    template<typename T>
    T queue<T>::rear()
    {
        if (isize == 0)
        {
            throw out_of_range("size를 초과한 연산입니다.");
        }
        return arr[isize - 1];
    }
    
    template<typename T>
    int queue<T>::size()
    {
        return isize;
    }
    
    template<typename T>
    void queue<T>::fmaxSize(T t)
    {
        void* temp = realloc(arr, sizeof(T) * t);
        if (temp == NULL)
        {
            return;
        }
        arr = (T*)temp;
        isConstSize = true;
        maxSize = t;
    }
    
    int main()
    {
        queue<int> q;
        for (int i = 0; i < 6; i++)
        {
            q.push(i);
        }
        for (int i = 0; i < 6; i++)
        {
            cout << "front : " << q.front() << "\t";
            cout << "rear : " << q.rear() << endl;
            q.pop();
        }
        return 0;
    }
```

- 직접 큐 자료구조를 재현해서 그 큐로 값을 넣고 빼는 것을 출력하는 코드이다.
- 예전에 손수 스택을 구현한 경험이 있었기에 스택을 구현 했을 당시보다 더욱 쉽게 구현 할 수 있었고 그때에서 더 추가해서 throw를 통해 오류 처리도 하였다.
- 사소한 느낀 점이지만 처음 코드를 작성했을 때 비해서 보이는 코드가 확실히 깔끔해진게 눈에 보여서 다행이다는 생각이 든다.

```cpp
    // 1-2번 문제

    #include <iostream>
    using namespace std;
    
    template<typename T>
    class queue {
    private:
        T* arr;
        int isize;
        int maxSize;
        bool isConstSize;
    public:
        queue();
        ~queue();
        void push(T t);
        void pop();
        T front();
        T rear();
        int size();
        void fmaxSize(T t);
    };
    
    template<typename T>
    queue<T>::queue()
    {
        arr = (T*)malloc(0);
        isize = 0;
        maxSize = 0;
        isConstSize = false;
    }
    
    template<typename T>
    queue<T>::~queue()
    {
        free(arr);
    }
    
    template<typename T>
    void queue<T>::push(T t)
    {
        if (isConstSize)
        {
            if (maxSize <= isize)
            {
                cout << "크기를 초과하셨서요.." << "maxSize : " << maxSize << endl;
                return;
            }
        }
        if (maxSize > isize)
        {
            arr[isize] = t;
            isize++;
            return;
        }
        void* temp = realloc(arr, sizeof(T) * (isize + 1));
        if (temp == NULL)
        {
            return;
        }
        arr = (T*)temp;
        arr[isize] = t;
        isize++;
        maxSize = isize;
    }
    
    template<typename T>
    void queue<T>::pop()
    {
        if (isize == 0)
        {
            cout << "안에 든게 더 이상 없어요" << endl;
            //throw out_of_range("size가 0 이에요.");
            return;
        }
        for (int i = 0; i < isize; i++)
        {
            arr[i] = arr[i + 1];
        }
        isize--;
    }
    
    template<typename T>
    T queue<T>::front()
    {
        if (isize == 0)
        {
            cout << "size를 초과한 연산입니다." << endl;
            //throw out_of_range("size를 초과한 연산입니다.");
            return NULL;
        }
        return arr[0];
    }
    
    template<typename T>
    T queue<T>::rear()
    {
        if (isize == 0)
        {
            cout << "size를 초과한 연산입니다." << endl;
            //throw out_of_range("size를 초과한 연산입니다.");
            return NULL;
        }
        return arr[isize - 1];
    }
    
    template<typename T>
    int queue<T>::size()
    {
        return isize;
    }
    
    template<typename T>
    void queue<T>::fmaxSize(T t)
    {
        void* temp = realloc(arr, sizeof(T) * t);
        if (temp == NULL)
        {
            return;
        }
        arr = (T*)temp;
        isConstSize = true;
        maxSize = t;
    }
    
    int main()
    {
        queue<int> q;
        q.fmaxSize(4);
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            q.push(i);
        }
    
        for (int i = 0; i < 6; i++)
        {
            cout << "front : " << q.front() << "\t";
            cout << "rear : " << q.rear() << endl;
            q.pop();
        }
        return 0;
    }
```

- 이전에 구현한 큐를 이용해 크기를 초과시키거나 완전히 비운뒤 또 비우는 작업을 하게 해서 일부로 오류를 내는 코드이다.
- 위에 작성한 코드랑 크게 다를바가 없지만 출력하는 것을 보기 위해서 throw부분을 주석처리한 부분을 조금 바꿧다

```cpp
    // 1-3번 문제

    #include <iostream>
    using namespace std;
    
    #define NEXT(index, QSIZE) ((index+1) % QSIZE)
    
    typedef struct Queue {
        int* buf;
        int qsize;
        int front;
        int rear;
        int count;
    }Queue;
    
    void InitQueue(Queue* queue, int qsize);
    int IsFull(Queue* queue);
    int IsEmpty(Queue* queue);
    void Enqueue(Queue* queue, int data);
    int Dequeue(Queue* queue);
    
    int main()
    {
        int i, size;
        int select = -1;
    
        Queue queue;
    
        cout << "큐의 크기를 입력하세요. : ";
        cin >> size;
    
        InitQueue(&queue, size);
    
        while (true)
        {
            cout << "1. Enqueue 2. Dequeue" << endl;
            cout << " >> ";
            cin >> select;
    
            switch (select)
            {
            case 1:
                int value;
                cout << "input data : ";
                cin >> value;
                Enqueue(&queue, value);
                break;
    
            case 2:
                Dequeue(&queue);
                break;
            }
            cout << endl;
        }
    }
    
    void InitQueue(Queue* queue, int qsize)
    {
        queue->buf = new int[qsize];
        queue->qsize = qsize;
        queue->front = queue->rear = 0;
        queue->count = 0;
    }
    
    int IsFull(Queue* queue)
    {
        return queue->count == queue->qsize;
    }
    
    int IsEmpty(Queue* queue)
    {
        return queue->count == 0;
    }
    
    void Enqueue(Queue* queue, int data)
    {
        if (IsFull(queue))
        {
            cout << "큐가 꽉 찼음" << endl;
            return;
        }
        queue->buf[queue->rear] = data;
        queue->rear = NEXT(queue->rear, queue->qsize);
        queue->count++;
    }
    
    int Dequeue(Queue* queue)
    {
        int re = 0;
        if (IsEmpty(queue))
        {
            cout << "큐가 비엇음" << endl;
            return re;
        }
        re = queue->buf[queue->front];
        queue->front = NEXT(queue->front, queue->qsize);
        cout << "dequeue : " << re;
        queue->count--;
        return re;
    }
```

- 직접 구현한 원형 큐를 계속 반복해서 테스트 할 수 있게 만든 코드이다.
- 1-1, 1-2와 구조 자체가 다른데 원형 큐를 구현하기 어렵다고 생각해서 교과서를 참고하고 만들었기에 코드가 매우 많이 달라졌다.
- 교과서 코드를 보며 느낀 점으로 같은 내용을 다른 사람이 짜게 되면 완전히 다른 코드가 나오게 된다는 것이 신기했다.