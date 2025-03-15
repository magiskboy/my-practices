class Person{
public:
    int cur_id;
    string name;
    short age;
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person{
public:
    int publications;
    void getdata();
    void putdata();
};

class Student : public Person{
public:
    int mark[6];
    void getdata();
    void putdata();
};


void Professor::getdata(){
    cur_id = 1;
    cin >> name >> age >> publications;
}

void Professor::putdata(){
    cout << name << " " << age << " " << publications << " " << cur_id << endl;
}

void Student::getdata(){
    cur_id = 2;
    cin >> name >> age >> mark[0] >> mark[1] >> mark[2] >> mark[3] >> mark[4] >> mark[5];
}

void Student::putdata(){
    cout << name << " " << age << " " << mark[0] + mark[1] + mark[2] + mark[3] + mark[4] + mark[5] << " " << cur_id << endl;
}
