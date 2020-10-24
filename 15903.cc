//카드 합체 놀이
#define MY_METHOD

#ifdef MY_METHOD
#include <iostream>

using namespace std;

typedef struct pri_Qu{
	long long lVal;
	pri_Qu* ptNextNode;
}PriorQueue;

class priority_Queue{

public:
	PriorQueue* m_ptRoot;

	priority_Queue(void){
		m_ptRoot = new PriorQueue;
		m_ptRoot->ptNextNode = nullptr;
	};

	void AddNode(long long lVal)
	{
		PriorQueue* newNode = new PriorQueue;
		newNode->lVal = lVal;
		newNode->ptNextNode = nullptr;
		
		if (m_ptRoot->ptNextNode == nullptr)
		{
			m_ptRoot->ptNextNode = newNode;
		}
		else
		{
			PriorQueue* compareNode = m_ptRoot->ptNextNode;
			PriorQueue* tmpNode = nullptr;

			while(compareNode != nullptr)
			{
				if(newNode->lVal < compareNode->lVal)
				{
					newNode->ptNextNode = compareNode;
					
					if(tmpNode == nullptr)
					{
						m_ptRoot->ptNextNode = newNode;
					}
					else
					{
						tmpNode->ptNextNode = newNode; 
					}
				
					break;
				}

				tmpNode = compareNode;
				compareNode = compareNode->ptNextNode;
			}

			if(compareNode == nullptr && newNode->lVal >= tmpNode->lVal)
			{
				tmpNode->ptNextNode = newNode;
			}
		}
	};
	
	void Update(void)
	{
		PriorQueue* ptFront;
		PriorQueue* ptBack;
		long long lSum = 0;

		ptFront = m_ptRoot->ptNextNode;	
		ptBack =  ptFront->ptNextNode;
		m_ptRoot->ptNextNode = ptBack->ptNextNode;

		lSum =  ptFront->lVal + ptBack->lVal;

		AddNode(lSum);
		AddNode(lSum);
		
		delete ptFront;
		delete ptBack;
	};
	
	long long ALLSum(void)
	{
		long long lSum = 0;
		PriorQueue* ptEmpty;
	
		ptEmpty = m_ptRoot->ptNextNode;	
		
		while(!(ptEmpty == nullptr))
		{
			lSum += ptEmpty->lVal;
			ptEmpty = ptEmpty->ptNextNode;
		}

		return lSum; 
	};

	void Allprint(void)
	{
		PriorQueue* ptEmpty = m_ptRoot->ptNextNode;
		
		while(!(ptEmpty == nullptr))
		{
			cout << ptEmpty->lVal << endl;
			ptEmpty = ptEmpty->ptNextNode;
		}
	};
};

int main(void)
{
	int n = 0;
	int m = 0;
	priority_Queue oPriorQ;

	cin >> n >> m;

	for(register int i = 0; i < n; i++)
	{
		long long lTmp = 0;
		cin >> lTmp;
		oPriorQ.AddNode(lTmp);
	}

	for(register int i = 0; i < m; i++)
	{
		oPriorQ.Update();
	}

	cout << oPriorQ.ALLSum() << endl;

	return 0;
}

#else
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;


int main() {
 
	int n, m;
	scanf("%d%d", &n, &m);
	priority_queue<ll> pq;
	
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		pq.push(-tmp);
	}	
 
	while (m--) {
		ll f = -pq.top(); pq.pop();
		ll s = -pq.top(); pq.pop();
		ll sum = f + s;
		pq.push(-sum);
		pq.push(-sum);
	}

	ll ans = 0;

  	while (!pq.empty()) {
		ans += (-pq.top()); pq.pop();
	}	

   	printf("%lld", ans);
 
	return 0;
}
#endif