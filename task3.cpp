#include <iostream>
#include <vector>
std::vector<int> getindices(std::vector<int> array, int key){
	std::vector<int> indices;
	for (int i = 0; i < array.size(); i++){
		if (array[i] == key){
			indices.push_back(i);
		}
	}

	return indices;
}


int main(){
	std::vector<int> array = { 1,2,3,4,4,4,4,4,5,6,5,5,5 };
	int key = 5;

	std::cout << "key: " << key << std::endl;
	std::cout << "indices: ";
	std::vector<int> indices = getindices(array, key);
	for (int i = 0; i < indices.size(); i++){
		std::cout << indices[i] << std::endl;
	}

	int x;
	std::cin >> x;

	return 0;
}