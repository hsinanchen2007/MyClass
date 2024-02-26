#include <iostream>
#include <string>

class Person
{
public:
    Person(std::string theName);

    void introduce();

protected:
    std::string name;
};

class Teacher : public Person
{
public:
    Teacher(std::string theName, std::string theClass);

    void teach();
    void introduce();

protected:
    std::string classes;
};

class Student : public Person
{
public:
    Student(std::string theName, std::string theClass);

    void attendClass();
    void introduce();

protected:
    std::string classes;
};

class TeachingStudent : public Student, public Teacher
{
public:
    TeachingStudent(std::string theName, std::string classTeaching, std::string classAttending);

    void introduce();
};

Person::Person(std::string theName)
{
    name = theName;
}

void Person::introduce()
{
    std::cout << "��Һã�����" << name << "��\n\n";
}

Teacher::Teacher(std::string theName, std::string theClass) : Person(theName)
{
    classes = theClass;
}

void Teacher::teach()
{
    std::cout << name << "��" << classes << "��\n\n";
}

void Teacher::introduce()
{
    std::cout << "��Һã�����" << name << ", �ҽ�" << classes << "��\n\n";
}

Student::Student(std::string theName, std::string theClass) : Person(theName)
{
    classes = theClass;
}

void Student::attendClass()
{
    std::cout << name << "����" << classes << "ѧϰ��\n\n";
}

void Student::introduce()
{
    std::cout << "��Һã�����" << name << ", ����" << classes << "ѧϰ��\n\n";
}

TeachingStudent::TeachingStudent(std::string theName,
                                 std::string classTeaching,
                                 std::string classAttending)
                                 : Teacher(theName, classTeaching), Student(theName, classAttending)
{
}

void TeachingStudent::introduce()
{
    std::cout << "��Һã�����" << Student::name << "���ҽ�" << Teacher::classes << ", ";
    std::cout << "ͬʱ����" << Student::classes << "ѧϰ��\n\n";
}

int main()
{
    Teacher teacher("С����", "C++���Ű�");
    Student student("��;����", "C++���Ű�");
    TeachingStudent teachingStudent("����", "C++���Ű�", "C++���װ�");

    teacher.introduce();
    teacher.teach();
    student.introduce();
    student.attendClass();
    teachingStudent.introduce();
    teachingStudent.teach();
    teachingStudent.attendClass();

    return 0;
}
