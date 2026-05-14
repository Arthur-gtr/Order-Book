#include <stdlib.h>
#include <stdint.h>

#include "logger.h"

typedef struct Order
{
    size_t trader_id;
    size_t trade_value;
} Order;


typedef struct OrderBook
{
    size_t order_book_size;
    Order *asks_queu;
    Order *bids_queu;
} OrderBook;

void init_oder_book(OrderBook *order_book)
{
    order_book->order_book_size = 0;
    order_book->asks_queu = NULL;
    order_book->bids_queu = NULL;
}

void destroy_order_book(OrderBook *order_book)
{
    free(order_book->asks_queu);
    free(order_book->bids_queu);
}



int main(void)
{
    LOG_INFO("Start the order book");
    OrderBook order_book;
    init_oder_book(&order_book);
    

    LOG_DEBUG("Destroy Order Book");
    destroy_order_book(&order_book);
    LOG_INFO("Stop the order book");
    return EXIT_SUCCESS;
}