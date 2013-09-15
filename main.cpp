#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "./population.h"

void display(Individual *individual) {
  std::cout << "Formula : " << individual->formula() << std::endl;
  std::cout << "Value   : " << individual->value() << std::endl;
  std::cout << std::endl;
}

int main() {
  srand(time(NULL));

  int target;

  std::cout << "Enter target number: ";
  std::cin >> target;

  auto executor = make_shared<Executor>();

  auto current = make_shared<Population>(executor);

  auto generation = 0;

  while (target != current->fittest(target)->value()) {
    auto i = current->fittest(target);

    std::cout << "GENERATION: " << ++generation << std::endl;
    std::cout << "Fitness : " << i->fitness(target) << std::endl;
    display(i.get());

    auto new_population = make_shared<Population>(
      executor,
      current->offspring_sequences(target, Population::kSize));

    current = new_population;
  }

  auto winner = current->fittest(target);

  std::cout << "SOLUTION: " << std::endl;
  display(winner.get());
}

