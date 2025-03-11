# Customer Management System

## Overview
This program is designed to help a company manage customer data, track orders, and handle sales transactions efficiently. It utilizes file storage and various lookup functionalities to streamline customer service operations.

## Features

### 1. Customer Data Management
- Reads and stores customer information from `customers.txt`.
- Allows employees to look up customer details using either first name or ID number.

### 2. Order Tracking
- Reads `orders.txt` to check order status.
- Retrieves order details using an Order ID.
- Identifies when an order was placed.

### 3. Rainbow Tribles Queue System
- Manages a queue for customers waiting to receive rainbow tribles.
- Keeps track of customers eligible for the product upon arrival.
- Removes customers from the queue once they receive their order.

### 4. Customer Sales Handling
- Validates customer existence before processing an order.
- Captures order details such as quantity and price.
- Saves order transactions in `transactions.txt` and `orders.txt` for record-keeping.

## File Storage
The program relies on three text files for storing and retrieving data:
- `customers.txt` - Stores customer details.
- `orders.txt` - Records order information.
- `transactions.txt` - Logs customer sales transactions.

## Usage
This system helps company workers efficiently manage customers, track orders, handle special product queues, and process transactions while maintaining accurate records for future reference.

## Known Issues
- There is a known issue regarding ignoring a `bool` return value on **line 445 of `main.cpp`**. This may require further debugging to ensure correct handling of boolean expressions.
