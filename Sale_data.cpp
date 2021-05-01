#include<iostream>
#include <string>


struct Sale_data
{
    /* data */
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;	//销售数量 
    double revenue = 0.0;	//总销售额 
    double price = 0.0;	//单价 
};

int main()
{
//    Sale_data data1,data2;
//    std::cin >> data1.bookNo >> data1.units_sold >> data1.price;
//    data1.revenue = data1.price * data1.units_sold;
//    std::cout << data1.bookNo << " 的销售记录是：售出 " << data1.units_sold << " 本，总收入是 " << data1.revenue << std::endl;
//    std::cin >> data2.bookNo >> data2.units_sold >> data2.price;
//    data2.revenue = data2.price * data2.units_sold;
//    std::cout << data2.bookNo << " 的销售记录是：售出 " << data2.units_sold << " 本，总收入是 " << data2.revenue << std::endl;
//    if (data1.bookNo == data2.bookNo){
//    	unsigned totalCnt = data1.units_sold + data2.units_sold;
//    	double totalRevenue = data1.revenue + data2.revenue;
//    	std::cout << data1.bookNo << " 的销售记录是：共售出 " << totalCnt << " 本，总收入是 " <<  totalRevenue << " 平均每本价格 ";
//		if (totalCnt != 0)
//			std::cout << totalRevenue/totalCnt << std::endl;
//		else
//			std::cout << "(no sales)" << std::endl; 
//	}else{
//		sd::cerr << "Data must refer to the same ISBN" << std::endl;
//		return -1;
//	}

	Sale_data total;
	if (std::cin >> total.bookNo >> total.units_sold >> total.price){
		total.revenue = total.price * total.units_sold;
		Sale_data trans;
		int sum = 1;
		while (std::cin >> trans.bookNo >> trans.units_sold >> trans.price){
			trans.revenue = trans.price * trans.units_sold; 
			if (total.bookNo == trans.bookNo){
				total.units_sold += trans.units_sold;
				total.revenue += trans.revenue;
				total.price = total.revenue/total.units_sold;
				sum++; 
			}else{
				std::cout << total.bookNo << " 的销售记录有 " << sum << " 条，共售出 " << total.units_sold << " 本,总收入是 " << total.revenue << " 平均价格是 " << total.price << std::endl;
				total = trans;
				sum = 1;	 
			}
		}
		std::cout << total.bookNo << " 的销售记录有 " << sum << " 条，共售出 " << total.units_sold << " 本,总收入是 " << total.revenue << " 平均价格是 " << total.price << std::endl;	
	}
	return 0;
}


