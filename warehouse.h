#ifndef WARHOUSE_H
#define WARHOUSE_H

#include<iostream>
#include<string>
using namespace std;
class Product{
private:
    int Pid;
    string Pname;
    double Pprice;
    string Ptype;
    int Pcount;
    friend class Warehouse;
    friend class Record;
public:
    Product():Pid(0),Pname(" "),Pprice(0),Ptype(" "),Pcount(0){}
    Product(int i,string n,double p,string t, int c):Pid(i),Pname(n),Pprice(p),Ptype(t),Pcount(c){}
    ~Product(){}
    int getPid(){return Pid;}
    int getPcount(){return Pcount;}
    void setPcount(int c){Pcount=c;}
    void setPprice(double p){Pprice=p;}
};

class Warehouse{
private:
    Product *product;
    int index;
    int number;
    int size;
    int capacity;
    friend class WHmanagement;
public:
    Warehouse():product(NULL),index(0),number(0),size(0),capacity(5000){}
    Warehouse(int n,int i=0,int c=5000):index(i),number(n),size(0),capacity(c){
        product = new Product[number];
    }
    ~Warehouse(){
        delete [] product;
    }
    void addProduct(Product p){
        if(size>=capacity){
            cout<<"Warehouse is full"<<endl;
            return;
        }else if(size+p.getPcount()>capacity){
            cout<<"Warehouse can't hold these products"<<endl;
            return;
        }
        if(findProduct(p.Pid)!=NULL){
            product[findProduct(p.Pid)->Pid].setPcount(findProduct(p.Pid)->Pcount+p.Pcount);
            size+=p.Pcount;
            return;
        }else{
            product[index++]=p;
            size+=p.Pcount;
            return;
        }                                      //暂未考虑上新时，满种类的删减问题
    }
    
    Product* findProduct(string s){
        for(int i=0;i<index;i++){
            if(product[i].Pname==s){
                return &product[i];
            }
        }
        return NULL;
    }
    Product* findProduct(int i){
        for(int j=0;j<index;j++){
            if(product[j].Pid=i){
                return &product[j];
            }
        }
        return NULL;
    }
    void findType(string t){
        for(int i=0;i<index;i++){
            if(product[i].Ptype==t){
                cout<<product[i].Pname<<" "<<product[i].Pprice<<" "<<product[i].Pcount<<endl;
            }
        }
    }
    void subProduct(Product p){
        if(findProduct(p.Pid)==NULL){
            cout<<"Warehouse doesn't have this product"<<endl;
            return;
        }else{
            if(findProduct(p.Pid)->Pcount<p.Pcount){
                cout<<"Warehouse doesn't have enough products"<<endl;
            }else{
                findProduct(p.Pid)->Pcount-=p.Pcount;
                size-=p.Pcount;
            }
        }
    }
    void showProduct(){
        for(int i=0;i<index;i++){
            cout<<product[i].Pid<<" "<<product[i].Pname<<" "<<product[i].Pprice<<" "<<product[i].Ptype<<" "<<product[i].Pcount<<endl;
        }
    }
};





#endif // WARHOUSE_H