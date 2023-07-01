#pragma once

#include "Config.h"

//------------------------------------------------------------------------------------------------------------------
template<class T> class ASmart_Pointer
{
public:
	~ASmart_Pointer()
	{
		AsConfig::Text_Print_To_Console("ASmart_Pointer Destructor \n");
		delete Type_Pointer;
	}
	ASmart_Pointer(T *type_pointer) : Type_Pointer(type_pointer)
	{
		AsConfig::Text_Print_To_Console("ASmart_Pointer Constructor \n");
	}

	T& operator *()
	{
		return *Type_Pointer;
	}

private:
	T *Type_Pointer;
};
//------------------------------------------------------------------------------------------------------------------
template<class T> class AMain_Template
{
public:
	AMain_Template(const T &type_name) : Type_Name(type_name)
	{
	}

	void Get_Type_Size()
	{
		cout << "sizeof: " << sizeof(Type_Name) << endl;
	}
	T Get_Type()
	{
		return T();
	}

protected:
	T Type_Name;
};
//------------------------------------------------------------------------------------------------------------------
template<class T> class AsType_Info : public AMain_Template<T>
{
public:
	~AsType_Info()
	{		
		this->Get_Type_Size();
		Show_Type_Name();
	};
	AsType_Info(const T &type_name):AMain_Template<T>(type_name)
	{
	}
	void Show_Type_Name()
	{
		cout << "Type Name: " << typeid(this->Type_Name).name() << "\n" << endl;
	}
};
//------------------------------------------------------------------------------------------------------------------
template<class T> class APrinter_Template
{
public:
	void Print_Value(T value)
	{
		cout << value << endl;
	}
};
//------------------------------------------------------------------------------------------------------------------
template<> class APrinter_Template<std::string>
{// Partial specialization for std::string
public:
	void Print_Value(std::string value)
	{
		cout << "_____" << value << "_____" << endl;
	}
};
//------------------------------------------------------------------------------------------------------------------




// AList
template<class T> class AList
{
private:
	//------------------------------------------------------------------------------------------------------------------
	template<class AData_Type> class AsNode
	{
	public:
		~AsNode()
		{
		}
		AsNode(AData_Type data_type = AData_Type(), AsNode *node_next_pointer = 0)
			: Data_Type(data_type), Node_Next_Pointer(node_next_pointer)
		{
		}
		AData_Type Data_Type;
		AsNode *Node_Next_Pointer;
	};
	//------------------------------------------------------------------------------------------------------------------
public:
	~AList()
	{
		Clear();
	}
	AList()
	: i(0), List_Size(0), counter(0), Node_First(0), Curr_Ptr(0), Prev_Ptr(0), Temp(0)
	{
	}

	int i;
	int List_Size;
	int counter;
	AsNode<T> *Node_First;
	AsNode<T> *Curr_Ptr;
	AsNode<T> *Prev_Ptr;
	AsNode<T> *Temp;

	void Clear()
	{
		while ( (bool)List_Size)
			Pop_Front();
	}
	void Pop_Front()
	{
		Temp = Node_First;
		Node_First = Node_First->Node_Next_Pointer;
		delete Temp;
		List_Size--;
	}
	T& operator[](const int index)
	{
		Curr_Ptr = Node_First;
		counter = 0;

		while (Curr_Ptr != 0)
		{
			if (counter != index)
			{
				Curr_Ptr = Curr_Ptr->Node_Next_Pointer;
				counter++;
			}
			else
				return Curr_Ptr->Data_Type;
		}
		return Curr_Ptr->Data_Type;
	}
	int Get_List_Size() { return List_Size; }
	void Push_Back(T data_type)
	{
		if (Node_First == 0)
			Node_First = new AsNode<T>(data_type);
		else
		{
			Curr_Ptr = Node_First;  // can try this->  // Add new * and set head *

			while (Curr_Ptr->Node_Next_Pointer != 0)
				Curr_Ptr = Curr_Ptr->Node_Next_Pointer;

			Curr_Ptr->Node_Next_Pointer = new AsNode<T>(data_type);  // Target add new Object if prev don`t have ptr
		}
		List_Size++;
	}
	void Push_Front(T data_type)
	{
		Node_First = new AsNode<T>(data_type, Node_First);
		List_Size++;
	}
	void Insert(T data_type, int index)
	{
		if (index == 0)
			Push_Front(data_type);
		else
		{
			Prev_Ptr = Node_First;

			for (i = 0; i < index - 1; i++)
				Prev_Ptr = Prev_Ptr->Node_Next_Pointer;

			Temp = new AsNode<T>(data_type, Prev_Ptr->Node_Next_Pointer);
			Prev_Ptr->Node_Next_Pointer = Temp;
			List_Size++;
		}
	}
	void Remove_At(int index)
	{
		if (index == 0)
		{
			Pop_Front();
		}
		else
		{
			Prev_Ptr = Node_First;

			for (i = 0; i < index - 1; i++)
				Prev_Ptr = Prev_Ptr->Node_Next_Pointer;

			Temp = Prev_Ptr->Node_Next_Pointer;

			Prev_Ptr->Node_Next_Pointer = Temp->Node_Next_Pointer;

			delete Temp;

			List_Size--;
		}
	}
	void Pop_Back()
	{
		Remove_At(List_Size - 1);
	}
};
//------------------------------------------------------------------------------------------------------------------
template<class T> void Print_List(const list<T> &my_list)
{
	for (auto &it: my_list)
		cout << it << endl;
}
//------------------------------------------------------------------------------------------------------------------
