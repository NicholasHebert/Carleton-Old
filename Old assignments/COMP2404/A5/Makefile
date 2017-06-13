OBJ = main.o InvControl.o Store.o Product.o UI.o ProdArray.o Customer.o Purchase.o ProdList.o PurchArray.o Dairy.o CoffeeTea.o Bakery.o Meat.o MiscGoods.o Date.o	TaxationBehaviour.o	ExpirationBehaviour.o

cushop:	$(OBJ)
	g++ -o cushop $(OBJ)

main.o:	main.cc
	g++ -c main.cc

InvControl.o:	InvControl.cc InvControl.h Store.h UI.h
	g++ -c InvControl.cc

UI.o:	UI.cc UI.h
	g++ -c UI.cc

Store.o:	Store.cc Store.h ProdArray.h
	g++ -c Store.cc

Product.o:	Product.cc Product.h Date.h ExpirationBehaviour.h TaxationBehaviour.h
	g++ -c Product.cc

ProdArray.o:	ProdArray.cc ProdArray.h Product.h defs.h
	g++ -c ProdArray.cc

PurchArray.o:	PurchArray.cc PurchArray.h Purchase.h defs.h
	g++ -c PurchArray.cc

Customer.o:	Customer.cc Customer.h
	g++ -c Customer.cc

Purchase.o:	Purchase.cc Purchase.h
	g++ -c Purchase.cc

ProdList.o:	ProdList.cc ProdList.h
	g++ -c ProdList.cc

Dairy.o:	Dairy.cc Dairy.h Product.h ExpirationBehaviour.h	TaxationBehaviour.h
	g++ -c Dairy.cc

CoffeeTea.o:	CoffeeTea.cc CoffeeTea.h Product.h ExpirationBehaviour.h	TaxationBehaviour.h
	g++ -c CoffeeTea.cc

Bakery.o:	Bakery.cc Bakery.h Product.h ExpirationBehaviour.h	TaxationBehaviour.h
	g++ -c Bakery.cc

Meat.o:	Meat.cc Meat.h Product.h ExpirationBehaviour.h	TaxationBehaviour.h
	g++ -c Meat.cc

MiscGoods.o:	MiscGoods.cc MiscGoods.h Product.h ExpirationBehaviour.h	TaxationBehaviour.h
	g++ -c MiscGoods.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

TaxationBehaviour.o:	TaxationBehaviour.h
	g++ -c TaxationBehaviour.cc

ExpirationBehaviour.o:	ExpirationBehaviour.h	Date.h
	g++ -c ExpirationBehaviour.cc

clean:
	rm -f $(OBJ) cushop
