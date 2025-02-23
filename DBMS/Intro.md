# **DBMS Overview**  

## **Data**  

- Raw, unorganized facts without inherent meaning.  

### **Types**  

- **Quantitative** – Numeric values.  
- **Qualitative** – Descriptive attributes.  

## **Information**  

- Structured and processed data that provides context for decision-making.  

## **Database**  

- A digital system for storing, managing, and retrieving data efficiently.  

## **Database Management System (DBMS)**  

- A software suite that manages databases, enabling data storage, retrieval, modification, and deletion.


---

## **DBMS Architecture**  

### **1. Data Abstraction & Three-Schema Architecture**  

DBMS provides an abstract view of data to simplify user interaction and ensure efficient access. Abstraction is applied through multiple layers, allowing users to access the same data with personalized views while maintaining a single data storage.  

### **2. Levels of DBMS Architecture**  

#### **a) Internal (Physical) Level – How Data is Stored**  

- Lowest level of abstraction, dealing with physical storage details.  
- Defines **storage structures** like B-Trees, Hashing, and Indexing.  
- Manages **data compression, encryption, and storage allocation** (e.g., n-ary trees).  
- Focuses on optimizing **performance and retrieval efficiency**.  

#### **b) Conceptual (Logical) Level – What Data is Stored & Relationships**  

- Defines the **overall database structure** and relationships between entities.  
- Independent of physical storage, focusing on **logical organization**.  
- Designed by **DB Administrators (DBAs)** to determine what data should be stored.  
- Goal: Provide an **easy-to-use** and structured view of data.  

#### **c) External (View) Level – How Users See Data**  

- Highest level of abstraction, presenting **customized views** to different users.  
- Uses **view schemas and sub-schemas** to provide role-based access.  
- Implements **security mechanisms** to restrict unauthorized data access.  
- Simplifies user interaction by hiding complexity and providing relevant data subsets.

---

## **Instance and Schema**  

- A **database instance** is the **current snapshot** of stored data at a specific moment.  
- The **schema** defines the **overall structure** of the database, including tables, relationships, and constraints. Unlike data, which changes frequently, the schema remains relatively stable.  
- **Types of Schemas**:  
  1. **Physical Schema** – Defines how data is stored at the hardware level.  
  2. **Logical Schema** – Represents the database structure, including tables and relationships.  
  3. **View Schema** – Provides **customized views** for different users without altering underlying data.  
- **Physical Data Independence**: Changes in the **physical schema** (e.g., switching storage formats or indexing methods) should not impact the **logical schema** or application programs.  

---

## **Data Models**  

- A **data model** defines how data is structured, stored, and manipulated at the **logical level**.  
- It acts as a **conceptual framework** for describing **data, relationships, constraints, and rules**.  
- **Common Data Models**:  
  1. **Relational Model (SQL - MySQL, PostgreSQL, etc.)** – Represents data in **tables (relations)** with structured relationships and constraints (e.g., primary keys, foreign keys).  
  2. **Document-Oriented Model (MongoDB, Firebase, etc.)** – Stores data as **JSON-like documents** with a flexible schema (e.g., MongoDB).  
  3. **Entity-Relationship (ER) Model** – Uses entities, attributes, and relationships to design the database conceptually.  
  4. **Object-Oriented & Object-Relational Models** – Extends the relational model with object-oriented features like inheritance and encapsulation.  

---

## **Database Languages**  

- **DDL (Data Definition Language)** – Defines database structure (CREATE, ALTER, DROP).  
- **DML (Data Manipulation Language)** – Handles data retrieval and modification (INSERT, UPDATE, DELETE, SELECT).  

---

## **Accessing Database from Applications**  

- Applications (e.g., C++, Java) interact with databases using **DML statements** embedded in host languages.  
- APIs facilitate communication between applications and databases.  
- **Common APIs**:  
  - **ODBC (Open Database Connectivity)** – Supports multiple databases.  
  - **JDBC (Java Database Connectivity)** – Specifically for Java applications.  

---

## **Database Administrator (DBA)**  

- Works at the **logical level**, overseeing data and programs that access it.  
- Central control of **database security, integrity, and maintenance**.  
- **Key Responsibilities**:  
  - **Security** – Controls user access.  
  - **Performance** – Optimizes queries and indexing.  
  - **Backup & Recovery** – Ensures data availability and prevents loss.  
  - **Schema Management** – Maintains database design and structure.  

---

## **DBMS Application Architecture**  

### **1. Single-Tier Architecture**  

- Application and database reside on the **same system** (e.g., local applications).  

### **2. Two-Tier Architecture (Client-Server)**  

- The application is divided into **two components**:  
  - **Client** – Sends queries to the server.  
  - **Database Server** – Processes queries and returns results.  
- Example: Applications using **JDBC or ODBC** for database access.  

### **3. Three-Tier Architecture (Web-Based Applications)**  

- Divides the application into **three layers**:  
  1. **Client (Frontend UI)** – Does not interact with the database directly.  
  2. **Application Server (Business Logic)** – Handles application logic and processes user requests.  
  3. **Database Server** – Stores and manages data.  
- Example: Web apps where the **frontend communicates with an application server**, which in turn interacts with the database.  

### **4. N-Tier Architecture (Distributed Systems)**  

- Extends **three-tier architecture** by adding multiple layers to improve **scalability and modularity**.  
- Used in **cloud-based and enterprise applications**.  
- Example: **Microservices-based architectures** with independent data services.  
