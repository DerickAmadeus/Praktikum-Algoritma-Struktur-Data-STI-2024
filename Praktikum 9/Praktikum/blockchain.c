#include "listlinierv2.h"


infotype computeHash(BlockData block) {
    return block.prevHash + block.data + block.timestamp;
}


void initBlock(List *blockchain) {
    CreateEmpty(blockchain);
    BlockData genesisBlock;
    genesisBlock.prevHash = 0;
    genesisBlock.data = 'S' + 'a' + 't' + 'o' + 'm' + 'o' + 't' + 'o';
    genesisBlock.timestamp = 0;
    InsVLast(blockchain, genesisBlock.prevHash, genesisBlock.data, genesisBlock.timestamp);
}


void addBlock(List *blockchain, infotype value, infotype timestamp) {
    if (IsEmpty(*blockchain)) {
        printf("Blockchain kosong. Tambahkan genesis block terlebih dahulu.\n");
        return;
    }

    address lastBlock = First(*blockchain);
    while (Next(lastBlock) != Nil) {
        lastBlock = Next(lastBlock);
    }

    BlockData newBlock;
    newBlock.prevHash = computeHash(Info(lastBlock));
    newBlock.data = value;
    newBlock.timestamp = timestamp;

    InsVLast(blockchain, newBlock.prevHash, newBlock.data, newBlock.timestamp);
}


boolean validateChain(List blockchain) {
    if (IsEmpty(blockchain) || Next(First(blockchain)) == Nil) {
        return true;
    }

    address current = First(blockchain);
    address nextBlock = Next(current);

    while (nextBlock != Nil) {
        if (computeHash(Info(current)) != PrevHash(nextBlock)) {
            return false;
        }
        current = nextBlock;
        nextBlock = Next(current);
    }

    return true;
}


void printBlockchain(List blockchain) {
    if (IsEmpty(blockchain)) {
        printf("[]\n");
        return;
    }

    printf("[\n");
    address current = First(blockchain);
    int blockIndex = 1;

    while (current != Nil) {
        printf("  Block %d: {\n", blockIndex);
        printf("    prevHash: %llu,\n", PrevHash(current));
        printf("    data: %llu,\n", Data(current));
        printf("    timestamp: %llu\n", Timestamp(current));
        printf("  }");
        if (Next(current) != Nil) {
            printf(",");
        }
        printf("\n");
        current = Next(current);
        blockIndex++;
    }
    printf("]\n");
}


double getAverageData(List blockchain) {
    if (IsEmpty(blockchain)) {
        return 0.0;
    }

    address current = First(blockchain);
    double sum = 0.0;
    int count = 0;

    while (current != Nil) {
        sum += Data(current);
        count++;
        current = Next(current);
    }

    return sum / count;
}

address findLargestDataBlock(List blockchain) {
    if (IsEmpty(blockchain)) {
        return Nil;
    }

    address largestBlock = First(blockchain);
    address current = Next(largestBlock);

    while (current != Nil) {
        if (Data(current) > Data(largestBlock)) {
            largestBlock = current;
        }
        current = Next(current);
    }

    return largestBlock;
}
