#include "File.h"

Block File::getBlock(int index) const
{
	/* TODO */
	Block emptyBlock;
    return (blocks.getNodeAtIndex(index) ? blocks.getNodeAtIndex(index)->data : emptyBlock);
}

size_t File::fileSize() const
{
	/* TODO */
	if (isEmpty()) return 0;
    else{
        Node<Block> *current = blocks.getFirstNode();
        size_t result = 0;
        while (current != NULL) {
            result += current->data.getSize();
            current = current->next;
        }
        return result;
    }
}

int File::numBlocks() const
{
	/* TODO */
	return blocks.getSize();
}

bool File::isEmpty() const
{
	/* TODO */
	return blocks.isEmpty();
}

bool File::operator==(const File &rhs) const
{
	/* TODO */
    if (blocks.getSize() != rhs.blocks.getSize()) {
        return false;
    }
    Node<Block> *current1 = blocks.getFirstNode();
    Node<Block> *current2 = rhs.blocks.getFirstNode();

    while (current1 != NULL || current2 !=NULL) {
        if (!(current2->data == current1->data)) return false;
        current1 = current1->next;
        current2 = current2->next;
    }

    return true;
}

void File::newBlock(const Block &block)
{
	/* TODO */
	blocks.append(block);
}

void File::removeBlock(int index)
{
	/* TODO */
	if (index < 0 || index >= blocks.getSize()) {
        return;
    }
    blocks.removeNodeAtIndex(index);
}

void File::mergeBlocks(int sourceIndex, int destIndex)
{
	/* TODO */
	blocks.mergeNodes(sourceIndex,destIndex);
}

void File::printContents() const{
	if(isEmpty()){
		std::cout << "File is empty" << std::endl;
	}
	else{
		for(int i = 0; i < blocks.getSize(); i++){
			Node<Block> *block = blocks.getNodeAtIndex(i);
			std::cout << block->data.getContent();
		}
		std::cout << std::endl << fileSize() << std::endl;
	}
}