#include <stdlib.h>
#include <stdint.h>

#include "logger.h"
#include "order_book.h"

 int init_order_book(OrderBook *order_book) {
    order_book->asks.size = 0;
    order_book->asks.capacity = 100;
    order_book->asks.orders = malloc(order_book->asks.capacity * sizeof(Order));

    order_book->bids.size = 0;
    order_book->bids.capacity = 100;
    order_book->bids.orders = malloc(order_book->bids.capacity * sizeof(Order));
    if (order_book->bids.orders == NULL || order_book->asks.orders == NULL)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

void destroy_order_book(OrderBook *order_book) {
    free(order_book->asks.orders);
    free(order_book->bids.orders);
}

int main(void)
{
    LOG_INFO("Start the order book");
    OrderBook order_book;
    if (init_oder_book(&order_book) == EXIT_FAILURE){
        LOG_FATAL("Init order book fail");
        return EXIT_FAILURE;
    }

    destroy_order_book(&order_book);
    LOG_DEBUG("Destroy Order Book");
    LOG_INFO("Stop the order book");
    return EXIT_SUCCESS;
}