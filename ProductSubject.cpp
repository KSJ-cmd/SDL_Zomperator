#include"ProductSubject.h"

//void ProductSubject::UseMoney(int _money)
//{
//	for (IObserver* ob : m_Observers) {
//		dynamic_cast<ResourceObserver*>(ob)->updata_money(_money);
//	}
//}
//
//void ProductSubject::TakeResrc(int _takeAmount)
//{
//	for (IObserver* ob : m_Observers) {
//		dynamic_cast<ResourceObserver*>(ob)->updata_Resrc(_takeAmount);
//	}
//}
//
//void ProductSubject::Attach(IObserver* observer)
//{
//	m_Observers.push_back(observer);
//}
//
//void ProductSubject::Detach(IObserver* observer)
//{
//	m_Observers.remove(observer);
//}
//
//void ProductSubject::Notify(IObserver* _observer)
//{
//	for (IObserver* ob : m_Observers) {
//		ob->Observer_update();
//	}
//}
