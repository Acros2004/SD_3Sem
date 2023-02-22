#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;




struct Node
{
	char ch;
	int chactota;
	Node* left, * right;
};


Node* addNode(char ch, int chac, Node* left, Node* right)
{
	Node* node = new Node();

	node->ch = ch;
	node->chactota = chac;
	node->left = left;
	node->right = right;

	return node;
}


struct prioritet
{
	bool operator()(Node* l, Node* r)
	{

		return l->chactota > r->chactota;
	}
};


void code(Node* top, string str,unordered_map<char, string>& huffmanCode)
{
	if (top == nullptr)
		return;


	if (!top->left && !top->right) {
		huffmanCode[top->ch] = str;
	}

	code(top->left, str + "0", huffmanCode);
	code(top->right, str + "1", huffmanCode);
}


int main()
{
	setlocale(LC_ALL, "ru");
	string text,forOne = "";
	float sumAmount = 0;

	cout << "Введите ваш текст" << endl;
	getline(cin,text);


	unordered_map<char, int> chactota;
	for (char ch : text) {
		chactota[ch]++;
		sumAmount++;
	}

	
	for (const auto& key_value : chactota) {
		char key = key_value.first;
		int value = key_value.second;
		float sum = (value*100)/sumAmount;
		cout << key << " - " << value<< "\t" << sum << "%" << endl;
	}
	priority_queue<Node*, vector<Node*>, prioritet> queue;

	
	for (auto pair : chactota) {
		queue.push(addNode(pair.first, pair.second, nullptr, nullptr));
	}

	if (queue.size() == 1) {
		cout << "\nВыходная строка :\n";
		for (int i = 0; i < sumAmount; i++) {
			cout<<"1";
		}
		return 0;
	}
	while (queue.size() != 1)
	{
		
		Node* left = queue.top(); queue.pop();
		Node* right = queue.top();	queue.pop();

		
		int sum = left->chactota + right->chactota;
		queue.push(addNode('\0', sum, left, right));
	}

	
	Node* top = queue.top();

	
	unordered_map<char, string> huffmanCode;
	code(top, "", huffmanCode);

	for (auto pair : huffmanCode) {
		cout << pair.first << " " << pair.second << '\n';
	}


	string str = "";
	for (char ch : text) {
		str += huffmanCode[ch];
	}

	cout << "\nВыходная строка :\n" << str << '\n';

	
	int index = -1;

}