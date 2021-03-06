#include "Tree.h"

#include <iostream>

int main()
{
    Tree<int>* t;
    Tree<int>* t1;

    try
    {
        std::cout << "Создаём деревья t и t1(5)\n\n";
        t = new Tree<int>;
        t1 = new Tree<int>(5);
    }
    catch(TException& ex)
    {
        std::cout << ex.get_error_name() << std::endl;
    }

    std::cout << "Вывод пустого дерева t:" << std::endl;
    t->print_tree();

    std::cout << "\nВывод дерева t1:" << std::endl;
    t1->print_tree();

    try
    {
        std::cout << "\nДобавим 1 в первое дерево и 2 во второе"<< std::endl;
        t->push(1);
        t1->push(2);
    }
    catch(TException& ex)
    {
        std::cout << ex.get_error_name() << std::endl;
    }

    std::cout << "Вывод дерева t:" << std::endl;
    t->print_tree();

    std::cout << "\nВывод дерева t1:" << std::endl;
    t1->print_tree();

    std::cout << "\nОчистим дерево t" << std::endl;
    t->clear();
    std::cout << "Вывод дерева t:" << std::endl;
    t->print_tree();

    try
    {
        std::cout << "\nДобавим в дерево элементы со значениями 1, 2, 6" << std::endl;
        t1->push(1);
        t1->push(2);
        t1->push(6);
    }
    catch( TException& ex)
    {
        std::cout << ex.get_error_name() << std::endl;
    }

    std::cout << "\nВывод дерева:" << std::endl;
    t1->print_tree();

    try
    {
        std::cout << "\nУдалим из дерева узел со значением 2" << std::endl;
        t1->remove(2);
        std::cout << "Вывод дерева:" << std::endl;
        t1->print_tree();
    }
    catch(TException& ex)
    {
        std::cout << ex.get_error_name() << std::endl;
    }

    try
    {
        std::cout << "\nДобавим в дерево элементы со значениями 2, 3, 1" << std::endl;
        t1->push(2);
        t1->push(3);
        t1->push(1);
    }
    catch( TException& ex)
    {
        std::cout << ex.get_error_name() << std::endl;
    }

    std::cout << "Вывод дерева:" << std::endl;
    t1->print_tree();

    std::cout << "\nВырежем узел со значением 2" << std::endl;
    t1->cut(2);
    std::cout << "Вывод дерева:" << std::endl;
    t1->print_tree();

    std::cout << "\nМинимальное значение в дереве: " << t1->min()
              << "\nМаксимальное значение в дереве:" << t1->max() << std::endl;

    std::cout << "\nГлубина дерева = " << t1->depth() << std::endl;

    try
    {
        std::cout << "\nДобавим элементы в дерево t" << std::endl;
        t->push(10);
        t->push(5);
        t->push(7);
        t->push(1);
        t->push(0);
    }
    catch(TException& ex)
    {
        std::cout << ex.get_error_name() << std::endl;
    }

    std::cout << "Вывод дерева t:" << std::endl;
    t->print_tree();

    std::cout << "Добавим поддерево t в дерево t1" << std::endl;
    t1->add_subtree(*t);

    std::cout << "Вывод дерева t1:" << std::endl;
    t1->print_tree();

    std::cout << "\nГлубина дерева t1 = " << t1->depth() << std::endl;

    Tree<int> t2 = t1->get_subtree(10);

    t2.print_tree();

    auto func = [] (Node<int>* node)
    {
        if(node != nullptr)
        {
            std::cout << node->data << std::endl;
        }
    };

    t1->breadth_first_traversal(func);

    std::cout << "\nHello, World!" << std::endl;

    return 0;
}