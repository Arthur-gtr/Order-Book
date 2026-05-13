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
    Order trade_min;
    Order trade_max;

    size_t order_book_size;
    Order *asks;
    Order *bids;
} OrderBook;

void init_oder_book(OrderBook *order_book)
{
    order_book->trade_min = (Order) {0, 0};
    order_book->trade_max = (Order) {0, 0};

    order_book->order_book_size = 0;
    order_book->asks = NULL;
    order_book->bids = NULL;
}

void destroy_order_book(OrderBook *order_book)
{
    free(order_book->asks);
    free(order_book->bids);
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