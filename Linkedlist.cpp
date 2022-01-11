#include <iostream>
#include <stdlib.h>

using namespace std;

class Node
{
	public:
		int data;
		Node *next;
		Node()
		{
			data=data;
			next=NULL;
		}
};

class SingleLL
{
	public:
	Node *head;
	Node *sorted;
	
	void Them(int val)
	{
		cout << "Nhap mot so: ";
		cin >> val;
	    Node *a = new Node();
	    a->data = val;
	    a->next = NULL;
	    if (head == NULL) 
		{
	        a->next = head;
	        head = a;
	    }
	    else 
		{
	        Node *b = head;
	        while (b->next != NULL) 
			{
	            b = b->next;
	        }
	        a->next = b->next;
	        b->next = a;
	    }
	    cout << "\n";
	}
	
	void Tim(int key)
	{
		cout << "Nhap du lieu can tim: ";
		cin >> key;
	    Node *p = head;
	    while (p!=NULL) 
		{
	        if (p->data == key) 
			{
	            cout << p->data << " co ton tai trong danh sach";
	            cout << "\n\n";
	            return;
	        }
	        p = p->next;
	    }
	    if (p == NULL)
	    cout << "Khong co thong tin\n\n";
	}
	
	void Max()
	{
		Node *p = head;
		int max;
		if(p == NULL)
		{
			cout << "Khong co thong tin\n"<< endl;
		}
		else
		{
			max=p->data;
			while (p != NULL)
			{
				if(max < p->data)
				{
					max=p->data;
				}
				p=p->next;
			}
			cout << "Gia tri lon nhat trong danh sach la: " << max << "\n" << endl;
		}
	}
	
	void Min()
	{
		Node *p = head;
		int min;
		if(p == NULL)
		{
			cout << "Khong co thong tin\n"<< endl;
		}
		else
		{
			min = p->data;
			while (p != NULL)
			{
				if(min > p->data)
				{
					min = p->data;
				}
				p=p->next;
			}
			cout << "Gia tri be nhat trong danh sach la: " << min << "\n" << endl;
		}
	}
	
	void swap_node(Node *p, Node *q, int data)
	{
		int temp = p->data;
		p-> data = q->data;
		q->data = temp;
	}

	void bubble_sort(int data)
	{
		int swap;
		if(head == NULL)
		{
			return;
		}
		do
		{	
			swap = 0;
			Node *p = head; 
			while(p->next != NULL) 
			{
				if (p->data > p->next->data) 
				{
					swap_node(p, p->next,data); 
	                swap = 1; 
				}
				p = p->next;
				//cout<<swap;
			}
		}
		while(swap); 
	}

	void selection_sort (int data)
	{
	    Node *q,*max;
	    Node *p = head;
	    int temp;
	    while (p!=NULL)
	    {
	        max=p;
	        q=p->next;
	        while (q!=NULL)
	        {
	            if(q->data > max->data)  
	            {
	            	max=q;	
				}
	            q=q->next;
	        }
	        temp=p->data;
	        p->data=max->data;
	        max->data=temp;
	        p=p->next;
	    }
	}
	
	void insertion_sort()
    {
    	Node *current = head;
    	sorted = NULL;
    	while(current!=NULL)
    	{
    		Node *next=current->next;
    		sapxep(current);
    		current=next;
		}
		head=sorted;
    }
    void sapxep(Node *new_node)
    {
		if(sorted==NULL || sorted->data>=new_node->data)
		{
			new_node->next=sorted;
			sorted=new_node;
		}
		else
		{
			Node *current = sorted;
			while(current->next!=NULL && current->next->data < new_node->data)
			{
				current=current->next;
			}
			new_node->next=current->next;
			current->next=new_node;
		}
	}
	
	void delete_ll()
    {
        Node *p;
        while (head != NULL)
        {
            p = head;
            head = head->next;
            free(p);
        }
        cout << "Danh sach da bi xoa\n" << endl;
    }
	
	void XemDS()
	{
	    Node *p = head;
	    if (p == NULL) 
		{
	        cout << "Khong co thong tin\n\n";
	    }
	    else 
		{
	        while (p != NULL) 
			{
	            cout << " | " << p->data << " | -->";
	            p = p->next;
	        }
	        cout<<" NULL";
	        cout << "\n\n";
	    }
	}
};

int main()
{
	SingleLL s;
	int val, chon, data;
	while(true) 
	{
	    cout << "1 - Them nut vao danh sach"<<endl;
	    cout << "2 - Tim kiem trong danh sach"<<endl;
	    cout << "3 - Tim gia tri lon nhat trong danh sach"<<endl;
	    cout << "4 - Tim gia tri nho nhat trong danh sach"<<endl;
	    cout << "5 - Hien thi danh sach lien ket"<<endl;
	    cout << "6 - Bubble sort (tang dan)"<<endl;
	    cout << "7 - Selection sort (giam dan)"<<endl;
	    cout << "8 - Insertion sort (tang dan)"<<endl;
	    cout << "9 - Xoa toan bo danh sach lien ket"<<endl;
	    cout << "0 - Thoat\n";
	    cout << "Nhap lua chon cua ban: ";
	    cin >> chon;
	    switch(chon)
	    {
	    	case 1: //them du lieu vao danh sach lien ket
		    	s.Them(val);
		    	break;
	    	case 2: //tim data trong danh sach lien ket
		        s.Tim(val);
		        break;
		    case 3: //hien thi danh sach 
		        s.Max();
		        break;
		    case 4: //hien thi danh sach 
		        s.Min();
		        break;
	        case 5: //hien thi danh sach 
		        s.XemDS();
		        break;
	        case 6: //sap xep danh sach bang bubble sort
				cout << "Danh sach truoc khi sap xep: ";
				s.XemDS();
		        cout << "Danh sach sau khi sap xep: ";
		        s.bubble_sort(data);
		        s.XemDS();
		        break;
		    case 7: //sap xep danh sach bang selection sort
		        cout << "Danh sach truoc khi sap xep: ";
				s.XemDS();
				cout << "Danh sach sau khi sap xep: ";
		        s.selection_sort(data);
		        s.XemDS();
		        break;
		    case 8: 
		    	cout << "Danh sach truoc khi sap xep: ";
				s.XemDS();
				cout << "Danh sach sau khi sap xep: ";
		        s.insertion_sort();
		        s.XemDS();
		        break;
		    case 9:
	        	s.delete_ll();
	        	break;
	        case 0: //thoat
	            exit(0);
	            break;
	        default:
	            cout << "\nKhong co lua chon nay\n\n";	
		}
	}
}
