#include <stdio.h>

int main() {
    int med_ids[5] = {1, 2, 3, 4, 5};
    char med_names[5][100] = {"Paracetamol", "Cough Syrup", "skin care", "Cofsilss", "Amoxillin"};
    float med_prices[5] = {20.0, 50.50, 75.25, 30.0, 45.0};
    int med_stock[5] = {100, 75, 100, 100, 100};
    int choice, id, quantity, found;
    float total_amt, gst_rate = 18.0, gst_amount, final_amount;
    int i;

    printf("Medical Billing System\n");

    do {
        printf("\nMENU:\n");
        printf("1. View Available Medicines \n");
        printf("2. Purchase Medicines\n");
        printf("3. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n Available Medicines:\n");
                printf("\nid\tName\t\tPrice\t\tStock\n");
                for (i = 0; i < 5; i++) {
                    printf("\n%d\t%s\t\t%.2f\t\t%d\n", med_ids[i], med_names[i], med_prices[i], med_stock[i]);
                }
                break;

            case 2:
                printf("\nEnter the medicine id to purchase:\n");
                scanf("%d", &id);
                found = 0;
                for (i = 0; i < 5; i++) {
                    if (med_ids[i] == id) {
                        found = 1;
                        printf("Enter the quantity to purchase: ");
                        scanf("%d", &quantity);
                        if (quantity <= med_stock[i]) {
                            total_amt = quantity * med_prices[i];
                            gst_amount = (total_amt * gst_rate) / 100;
                            final_amount = total_amt + gst_amount;
                            med_stock[i] -= quantity;
                            printf("Purchase Successful!\n");
                            printf("Total cost: INR %0.2f\n", final_amount);
                            printf("GST Amount: INR %0.2f\n", gst_amount);
                            printf("Remaining stock of %s: %d\n", med_names[i], med_stock[i]);
                        } else {
                            printf("Insufficient Stock. Available Stock: %d\n", med_stock[i]);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("Medicine not found with the given id.\n");
                }
                break;

            case 3:
                printf("Thank You for Purchasing!!\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);

return 0;
}
