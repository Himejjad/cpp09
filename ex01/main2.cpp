// void RPN::calc( void )
// {
// 	std::stringstream strs(text.c_str());
// 	std::string p_of_op;
// 	int result(0);
// 	while(strs >> p_of_op)
// 	{
// 		if (p_of_op.size() > 1 && !is_number(p_of_op))
// 			throw(badInput("Error : bad input"));
// 		if(is_number(p_of_op))
// 		{
// 			if (std::atoi(p_of_op.c_str()) > 10)
// 				throw(badInput("Error : bad input"));
// 			stk.push_back(std::atoi(p_of_op.c_str()));
// 		}
// 		else if (stk.size() >= 2 && p_of_op.size() == 1)
// 		{
// 			if(p_of_op == "+")
// 			{
// 				result = (*(stk.end() - 2)) + stk.back();
// 				stk.pop_back();
// 				stk.pop_back();
// 				stk.push_back(result);
// 			}
// 			else if(p_of_op == "-")
// 			{
// 				result = (*(stk.end() - 2)) - stk.back();
// 				stk.pop_back();
// 				stk.pop_back();
// 				stk.push_back(result);
// 			}
// 			else if(p_of_op == "*")
// 			{
// 				result = (*(stk.end() - 2)) * (stk.back());
// 				stk.pop_back();
// 				stk.pop_back();
// 				stk.push_back(result);
// 			}
// 			else if(p_of_op == "/")
// 			{
// 				if (stk.back() == 0)
// 					throw(badInput("Error : bad input"));
// 				result = (*(stk.end() - 2)) / stk.back();
// 				stk.pop_back();
// 				stk.pop_back();
// 				stk.push_back(result);
// 			}
// 		}
// 		else
// 			throw(badInput("Error : bad input"));
// 		p_of_op.clear();
// 	}
// 	if(stk.size() != 1)
// 		throw(badInput("Error : bad input"));
// 	std::cout << stk.back() << std::endl;
// }
// RPN::~RPN()
// {
// }
