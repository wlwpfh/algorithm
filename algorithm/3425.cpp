#include<stack>
#include<string>
#include<vector>
using namespace std;

// �̰� �迭�� �־ �ش� ���� ���� �ϱ� .. 
// �� ó���� �ԷµǴ� ��ɾ���� ���Ϳ� �����ϱ�
// end�� ������ n�� �Է¹ް� n���� ���ڸ� stack�� �ֱ�
// stack�� ���ڵ��� ���Ϳ� ����� ���ڿ� ��ɾ�� ����ϱ�  

stack<int> s;

int NUM(int a) {

}
void

int main() {
	char instruction[5];
	int in_count = 0;
	int num;
	int a, b, tmp;

	vector<string, int> v;
	bool errorCheck = false;
	while (1) {
		scanf("%s", instruction);
		if (instruction == "END")
			break;
		else if (instruction == "QUIT")
			return 0;
		else if (instruction == "NUM") {
			scanf("%d", &num);
			v.push(make_pair(instruction, num));
		}
		else {
			v.push_back(instruction);
		}
	}
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &tmp);
		s.push(tmp);



	}
	if (errorCheck == true || s.size() != 1) {
		printf("ERROR \n");


	}
	return 0;
}

//
//else if(str=="POP"){
//			s.pop();
//		}else if(str=="INV"){
//			tmp=s.top();
//			s.pop();
//			s.push(-tmp);
//		}else if(str=="DUP"){
//			s.push(s.top());
//		}
//		else if(str=="SWP"){
//			//�ι�°�� ù��° ���� �ٲٱ�
//			a=s.top();
//			s.pop();
//			b=s.top();
//			s.pop();
//			s.push(a);
//			s.push(b);
//		}else if(str=="ADD"){
//			a=s.top();
//			s.pop();
//			b=s.top();
//			s.pop();
//			s.push(a+b);
//		}else if(str=="SUB"){
//			a=s.top();
//			s.pop();
//			b=s.top();
//			s.pop();
//			s.push(b-a);
//		}else if(str=="MUL"){
//			a=s.top();
//			s.pop();
//			b=s.top();
//			s.pop();
//			s.push(b*a);
//		}else if(str=="DIV"){
//			a=s.top();
//			s.pop();
//			b=s.top();
//			s.pop();
//			s.push(b/a);
//		}else if(str=="MOD"){
//			a=s.top();
//			s.pop();
//			b=s.top();
//			s.pop();
//			s.push(b%a);
//		}else if(str=="QUIT"){
//			return 0;
////		}