#include "ast_and_symtab.h"
#include <stddef.h>
#include <string.h>

SymbolTableEntry symbolTable[100];
int symbolTableSize = 0;

SymbolTableEntry* findSymbol(char* name) {
    for (int i = 0; i < symbolTableSize; ++i) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return &symbolTable[i]; // Return a pointer to the found entry
        }
    }
    return NULL; // Return NULL if the symbol is not found
}

char* lookupType(IdentifierNode* node) {
    // Search the symbol table for the identifier
    SymbolTableEntry* entry = findSymbol(node->name);
    
    // If the identifier is found, return its type
    if (entry != NULL) {
        return entry->type;
    }
    
    // If not found, return NULL or report an error
    return NULL;
}

void checkAssignmentType(AssignmentNode* node) {
    char* leftType = lookupType(node->left);
    char* rightType = lookupType((IdentifierNode*)node->right);
    if (strcmp(leftType, rightType) != 0) {
        // Report error
    }
}