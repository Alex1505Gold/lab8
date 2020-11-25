#include <iostream>
#include <string>

struct SCP
{
    std::string name = "SCP_000";
    std::string klass = "not_stated";
    int scp_number = -1;
    SCP operator=(int a)
    {
        std::string name = "SCP_000";
        std::string klass = "not_stated";
        int scp_number = -1;
        return *this;
    }
};

std::ostream& operator<< (std::ostream& out, const SCP& scp)
{
    out << std::endl;
    out << "SCP_" << scp.scp_number << " \"" << scp.name << "\"" << std::endl;
    out << "Class of the object: " << scp.klass << std::endl;
    return out;
}

template <typename T, unsigned int size>
struct List_arr
{
    T value[size];
    unsigned int actual_size;
};

template <typename T, unsigned int size>
void constructor_l(List_arr<T, size>& la)
{
    la.actual_size = 0;
    for (int i = 0; i < size; ++i)
    {
        la.value[i] = 0;
    }
}

template <typename T, unsigned int size>
unsigned int size_of_la(List_arr<T, size>& la)
{
    return la.actual_size;
}

template <typename T, unsigned int size>
void push_end(List_arr<T, size>& la, T a)
{
    if (la.actual_size < size)
    {
        la.value[la.actual_size] = a;
        la.actual_size++;
    }
    else
    {
        std::cout << "List is full\n";
    }
}

template <typename T, unsigned int size>
void insert_index_l(List_arr<T, size>& la, T a, unsigned int index)
{
    if ((index < size) && (la.actual_size < size))
    {
        for (unsigned int i = la.actual_size; i > index; --i)
        {
            la.value[i] = la.value[i - 1];
        }
        la.value[index] = a;
        la.actual_size++;
    }
    else
    {
        std::cout << "Cannot do this operation\n";
    }
}

template <typename T, unsigned int size>
T take_begin_l(List_arr<T, size>& la)
{
    T rez = la.value[0];
    for (unsigned int i = 0; i < la.actual_size-1; ++i)
    {
        la.value[i] = la.value[i + 1];
    }
    la.value[la.actual_size - 1] = 0;
    la.actual_size--;
    return rez;
}

template <typename T, unsigned int size>
T take_end_l(List_arr<T, size>& la)
{
    T rez = la.value[la.actual_size - 1];
    la.value[la.actual_size - 1] = 0;
    la.actual_size--;
    return rez;
}

template <typename T, unsigned int size>
T take_index_l(List_arr<T, size>& la, unsigned int index)
{
    T rez = la.value[index];
    for (unsigned int i = index; i < la.actual_size - 1; ++i)
    {
        la.value[i] = la.value[i + 1];
    }
    la.value[la.actual_size - 1] = 0;
    la.actual_size--;
    return rez;
}

template <typename T, unsigned int size>
T value_index_l(List_arr<T, size>& la, unsigned int index)
{
    T rez = la.value[index];
    return rez;
}

template <typename T, unsigned int size>
int find_pos_l(List_arr<T, size>& la, T a)
{
    int index = -1;
    for (unsigned int i = 0; i < la.actual_size; ++i)
    {
        if (la.value[i] == a)
        {
            index = i;
            break;
        }
    }
    return index;
}

template <typename T, unsigned int size>
void desstructor_l(List_arr<T, size>& la)
{
    la.actual_size = 0;
    for (int i = 0; i < size; ++i)
    {
        la.value[i] = 0;
    }
}

template <typename T, unsigned int size>
void show_l(List_arr<T, size>& la)
{
    std::cout << "-------------" << std::endl;
    for (unsigned int i = 0; i < la.actual_size; ++i)
    {
        std::cout << la.value[i] << std::endl;
    }
    std::cout << "-------------" << std::endl;
}

int main()
{
    //проверка для стандартного типа
    List_arr<int, 4> la0;
    constructor_l(la0);
    push_end(la0, 5);
    push_end(la0, 9);
    push_end(la0, 28);
    std::cout << find_pos_l(la0, 9) << std::endl;
    insert_index_l(la0, 45, 2);
    show_l(la0);
    std::cout << take_index_l(la0, 2) << std::endl;
    std::cout << take_begin_l(la0) << std::endl;
    std::cout << take_end_l(la0) << std::endl;
    show_l(la0);
    desstructor_l(la0);

    //проверка для пользовательского типа
    SCP scp0, scp1, scp2, scp3;
    scp0.scp_number = 35;
    scp0.name = "Possessive Mask";
    scp0.klass = "Keter";
    scp1.scp_number = 96;
    scp1.name = "Shy guy";
    scp1.klass = "Keter";
    scp2.scp_number = 131;
    scp2.name = "Eye pods";
    scp2.klass = "Safe";
    scp3.scp_number = 343;
    scp3.name = "God";
    scp3.klass = "Safe";
    List_arr<SCP, 4> la1;
    constructor_l(la1);
    push_end(la1, scp0);
    push_end(la1, scp1);
    insert_index_l(la1, scp2, 1);
    show_l(la1);
    return 0;
}


