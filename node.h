#ifndef node_h
#define  node_h

class NODE{
	 int ord_number,qty;
	NODE *nextPtr;
public:
	NODE(int,int);
	~NODE();
  int get_value();
	void set_next(NODE *);
	NODE* get_next();
  int order_number();
};
typedef NODE* NodePtr;
int NODE::order_number()
{
  return ord_number;
}
NODE::NODE(int x, int y){
	ord_number=x;
  qty=y;
	nextPtr=NULL;
  cout<<"My order is "<<x<<endl;

}
int NODE::get_value(){
  int price;
  switch(ord_number){
    case 1:
      price=100*qty;
      return price;
    case 2:
      price=20*qty;
      return price;
    case 3:
      price=50*qty;
      return price;
  }
  return 0;
}

NODE* NODE::get_next(){
	return nextPtr;

}

void NODE::set_next(NODE *t){
	 nextPtr=t;

}

NODE::~NODE(){
	 //cout<<"deleting " <<ord_number<<endl;

}


#endif