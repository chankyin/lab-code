int productSelection();

double priceOf(int productId);

double purchase(){
  int productId = productSelection();
  std::cout << "How many? --> ";
  int quantity;
  std::cin >> quantity;
  std::cout << "Quantity: " << quantity << ", price: " << priceOf(productId) << std::endl;
  return quantity * priceOf(productId);
}
