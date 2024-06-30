#ifndef WHMANAGEMENT_H
#define WHMANAGEMENT_H
#include<iostream>
#include"warehouse.h"

class Record{
private:
    string type;
    int Pid;
    int Pcount;
    double Pprice;
    friend class WHmanagement;
public:
    Record():type(" "),Pid(0),Pcount(0),Pprice(0){}
    Record(string t,int i,int c,double p):type(t),Pid(i),Pcount(c),Pprice(p){}
    ~Record(){}
    void showRecord(){
        cout<<"Type: "<<type<<" "<<"Product ID: "<<Pid<<" "<<"Product count: "<<Pcount<<" "<<"Product price: "<<Pprice<<endl;
    }
    void setType(string t){
        type = t;
    }
    void RecordSet(Product p){
        Pid = p.Pid;
        Pcount = p.Pcount;
        Pprice = p.Pprice;
    }
};

class WHmanagement{
private:
    Warehouse wh;
    Record *record;
    int index;
public:
    WHmanagement():wh(),record(),index(0){}
    WHmanagement(int n,int i=0,int c=5000):wh(n,i,c),index(0){
        record = new Record[100];
    }
    ~WHmanagement(){};
    void inWarehouse(Product p){
        wh.addProduct(p);
        record[index].setType("in");
        record[index++].RecordSet(p);
    }
    void outWarehouse(Product p){
        wh.subProduct(p);
        record[index].setType("out");
        record[index++].RecordSet(p);
    }
    void showProduct(){
        wh.showProduct();
    }
    void searchProduct(string s){
        wh.findProduct(s);
    }
    void searchPdType(string t){
        wh.findType(t);
    }
    void showAllRecord(){
        for(int i=0;i<index;i++){
            record[i].showRecord();
        }
    }
    void showInRecord(){
        for(int i=0;i<index;i++){
            if(record[i].type=="in"){
                record[i].showRecord();
            }
        }
    }
    void showOutRecord(){
        for(int i=0;i<index;i++){
            if(record[i].type=="out"){
                record[i].showRecord();
            }
        }
    }

    
};



#endif // WHMANAGEMENT_H