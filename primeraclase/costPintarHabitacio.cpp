int main() {
double x1, x2; // Superfícies de les parets
double costPerLitre; // Cost per litre de pintura en euros
int mans = 2; // Número de mans de pintura
llegirDades(x1, x2, costPerLitre);
double costTotal = calcularCostPintura(x1, x2, costPerLitre, mans);
cout<< "La superfície total és: "<< 2 * x1 + 2 * x2<< " metres quadrats"<< endl;
cout<< "Caldran " << costTotal << " litres de pintura." << endl;
cout<< "El cost total de pintar les parets és: " << costTotal << " euros" << endl;
return 0;
}