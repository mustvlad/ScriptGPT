#ifndef AST_AND_SYMTAB_H
#define AST_AND_SYMTAB_H

// Forward declaration of ExpressionNode for use in AssignmentNode
struct ExpressionNode;

// Identifier Node
typedef struct {
    char* name;
    char* type;
    int scope;
} IdentifierNode;

// Expression Node
typedef struct ExpressionNode {
    // Fields representing an expression
    // For example, you might have type information, value, etc.
    char* type;
    int value;
    // ... other fields ...
} ExpressionNode;

// Assignment Node
typedef struct {
    IdentifierNode* left;  // Left-hand side of the assignment
    struct ExpressionNode* right; // Right-hand side of the assignment
} AssignmentNode;

// Symbol Table Entry
typedef struct {
    char* name;
    char* type;
    int scope;
} SymbolTableEntry;

#endif // AST_AND_SYMTAB_H
