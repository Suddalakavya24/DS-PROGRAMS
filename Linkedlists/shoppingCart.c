#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Available_amount;

struct cart
{
      int id, Quantity, cost_items;
      char name[30];
};
void Display(struct cart *cart)
{
      int i;
      printf("Elements present in the Cart are:\n");
      for (i = 0; i < current_num_items(cart); i++)
      {
            printf("%d", i);
            printf("Id: %d    Name: %s    Quantity: %d    Cost_items: %d\n", cart[i].id, cart[i].name, cart[i].Quantity, cart[i].cost_items);
      }
};

int current_num_items(struct cart *cart)
{
      int i = 0, c = 0;
      while (cart[i].id != -1)
      {
            c++;
            i++;
      }
      return c;
};

void Delete(int item_position, struct cart *cart)
{
      int i, j;
      for (j = 0; j < current_num_items(cart); j++)
      {
            if (cart[j].id == item_position)
            {
                  item_position = j + 1;
                  for (i = item_position - 1; i < current_num_items(cart); i++)
                  {
                        cart[i].id = cart[i + 1].id;
                        strcpy(cart[i].name, cart[i + 1].name);
                        cart[i].Quantity = cart[i + 1].Quantity;
                        cart[i].cost_items = cart[i + 1].cost_items;
                  }
            }
      }

      if (current_num_items(cart) == 0)
            printf("Cart is Empty");
      else
            Display(cart);
};

int cost_items(struct cart *cart)
{
      int i, totalCost_items = 0;
      for (i = 0; i < current_num_items(cart); i++)
      {
            totalCost_items = totalCost_items + cart[i].cost_items;
      }
      return totalCost_items;
};

void Add_items_cart(struct cart temperory_item, struct cart *cart)
{
      int lastIndex, item_positionition;
      char choice;
      if ((cost_items(cart) + temperory_item.cost_items) > Available_amount)
      {
            printf(" Please remove some item(s).\n", Available_amount);
            printf("Do you want to remove now?(Y/N)");
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y')
            {
                  printf("Enter ID of the element to be Deleted: ");
                  scanf("%d", &item_positionition);
                  Delete(item_positionition, cart);
            }
      }
      else
      {
            lastIndex = current_num_items(cart);
            cart[lastIndex].id = temperory_item.id;
            strcpy(cart[lastIndex].name, temperory_item.name);
            cart[lastIndex].Quantity = temperory_item.Quantity;
            cart[lastIndex].cost_items = temperory_item.cost_items;
            Display(cart);
      }
};

void Search(int x, struct cart *cart)
{
      int i;
      if (current_num_items(cart) == 0)
      {
            printf("No items in cart to search");
      }
      else
      {
            for (i = 0; i < current_num_items(cart); i++)
            {
                  if (cart[i].id == x)
                  {
                        printf("Id: %d\tName: %s\tQuantity: %d\t\tCost_items: %d\n", cart[i].id, cart[i].name, cart[i].Quantity, cart[i].cost_items);
                  }
            }
      }
};

void SortByCost_items(struct cart *cart)
{
      int i, j;
      struct cart temperory_item;
      if (current_num_items(cart) == 0)
      {
            printf("No Items in cart to sort");
      }
      else
      {
            for (i = 0; i < current_num_items(cart); i++)
            {
                  for (j = i + 1; j < current_num_items(cart); j++)
                  {
                        if (cart[j].cost_items < cart[i].cost_items)
                        {
                              temperory_item.id = cart[j].id;
                              cart[j].id = cart[i].id;
                              cart[i].id = temperory_item.id;

                              strcpy(temperory_item.name, cart[i].name);
                              strcpy(cart[i].name, cart[j].name);
                              strcpy(cart[j].name, temperory_item.name);

                              temperory_item.Quantity = cart[j].Quantity;
                              cart[j].Quantity = cart[i].Quantity;
                              cart[i].Quantity = temperory_item.Quantity;

                              temperory_item.cost_items = cart[j].cost_items;
                              cart[j].cost_items = cart[i].cost_items;
                              cart[i].cost_items = temperory_item.cost_items;
                        }
                  }
            }
      }
};
void main()
{
      printf("Enter your available amount: ");
      scanf("%d", &Available_amount);
      struct cart temperory_item, cart[100];
      int i, item, element, item_positionition, option;
      char choice = 'y';
      for (i = 0; i < 100; i++)
            cart[i].id = -1;
      while (choice == 'y')
      {

            printf("\t Add Items into the cart\n");
            printf("\tDelete Items from the cart\n");
            printf("\t Display them in sorted  order based on Cost_items\n");
            printf("\tSearch Items in the cart\n");
            printf("\tDisplay all The Items\n");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                  printf("Enter the Details of the Item : name ,id,quantity,cost of items \n\n");
                  printf("Enter name of Item: ");
                  scanf("%s", temperory_item.name);
                  printf("Enter ID of Item: ");
                  scanf("%d", &temperory_item.id);
                  printf("Enter Quantity: ");
                  scanf("%d", &temperory_item.Quantity);
                  printf("Enter cost_items of Item: ");
                  scanf("%d", &temperory_item.cost_items);
                  Add_items_cart(temperory_item, cart);
                  break;
            case 2:
                  if (current_num_items(cart) == 0)
                  {
                        printf("ERROR: No Items in Cart\n");
                  }
                  else
                  {
                        printf("Enter ID of element to be Deleted: ");
                        scanf("%d", &item_positionition);
                        Delete(item_positionition, cart);
                  }
                  break;
            case 3:
                  SortByCost_items(cart);
                  Display(cart);
                  break;
            case 4:
                  printf("Enter Item ID for searching ");
                  scanf("%d", &element);
                  Search(element, cart);
                  break;
            case 5:
                  Display(cart);
                  break;
            }
            printf("\nDo you want to  add Items again?(Y/N):");
            scanf(" %c", &choice);
      }
}
