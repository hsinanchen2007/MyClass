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
    std::cout << "大家好，我是" << name << "。\n\n";
}

Teacher::Teacher(std::string theName, std::string theClass) : Person(theName)
{
    classes = theClass;
}

void Teacher::teach()
{
    std::cout << name << "教" << classes << "。\n\n";
}

void Teacher::introduce()
{
    std::cout << "大家好，我是" << name << ", 我教" << classes << "。\n\n";
}

Student::Student(std::string theName, std::string theClass) : Person(theName)
{
    classes = theClass;
}

void Student::attendClass()
{
    std::cout << name << "加入" << classes << "学习。\n\n";
}

void Student::introduce()
{
    std::cout << "大家好，我是" << name << ", 我在" << classes << "学习。\n\n";
}

TeachingStudent::TeachingStudent(std::string theName,
                                 std::string classTeaching,
                                 std::string classAttending)
                                 : Teacher(theName, classTeaching), Student(theName, classAttending)
{
}

void TeachingStudent::introduce()
{
    std::cout << "大家好，我是" << Student::name << "。我教" << Teacher::classes << ", ";
    std::cout << "同时我在" << Student::classes << "学习。\n\n";
}

int main()
{
    Teacher teacher("小甲鱼", "C++入门班");
    Student student("迷途羔羊", "C++入门班");
    TeachingStudent teachingStudent("丁丁", "C++入门班", "C++进阶班");

    teacher.introduce();
    teacher.teach();
    student.introduce();
    student.attendClass();
    teachingStudent.introduce();
    teachingStudent.teach();
    teachingStudent.attendClass();

    return 0;
}
