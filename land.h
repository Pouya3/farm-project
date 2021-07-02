#ifndef LAND_H
#define LAND_H


class Land {
protected:
    int time;
    int level;
    int space;
    int status;
    bool is_active;

public:
    Land();

    virtual void Upgrade();
    void Cultivation();
    int Get_time();
    void Set_time(int);
};

#endif // LAND_H