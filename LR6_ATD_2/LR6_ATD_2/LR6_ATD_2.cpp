#include<iostream>
using namespace std;


struct Node
{
	int d;
	Node* father;
	Node* left;
	Node* right;
	Node() { father = right = left = NULL; }
};

Node* root = NULL;

void pushHeap(Node*& root, int val)
{
	Node* z = new Node;
	z->d = val;
	if (root == NULL)
	{
		root = z;
		return;
	}
	Node* y = NULL, * x = root;
	while (x)
	{
		y = x;
		if (z->d < x->d)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->father = y;
	if (y->d > z->d)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
}


void buildHeap(Node* root, int* N, int size)
{
	for (int i = 0; i < size; i++)
	{
		pushHeap(root, N[i]);
	}
}


void popHeap(Node*& root, int* N, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		N[i] = N[i + 1];
	}
	buildHeap(root, N, size - 1);
}


void heapify(int arr[], int n, int i)
{
	int largest = i;
	// Инициализируем наибольший элемент как корень
	int l = 2 * i + 1; // левый = 2*i + 1
	int r = 2 * i + 2; // правый = 2*i + 2

 // Если левый дочерний элемент больше корня
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Если правый дочерний элемент больше, чем самый большой элемент на данный момент
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Если самый большой элемент не корень
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Рекурсивно преобразуем в двоичную кучу затронутое поддерево
		heapify(arr, n, largest);
	}
}


void peekHeap(int* N)
{
	cout << "Корень пирамиды: " << N[0] << endl;
}


void heapSort(int arr[], int n)
{
	// Построение кучи (перегруппируем массив)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Один за другим извлекаем элементы из кучи
	for (int i = n - 1; i >= 0; i--)
	{
		// Перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// вызываем процедуру heapify на уменьшенной куче
		heapify(arr, i, 0);
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	
	int size;
	cout << "Введите разммер массива: ";
	cin >> size;
	int* N = new int[size];
	cout << "Введите массив: ";
	for (int i = 0; i < size; i++)
	{
		cin >> N[i];
	}
	buildHeap(root, N, size);
	peekHeap(N);
	heapSort(N, size);
	peekHeap(N);
}











