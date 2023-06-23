#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "the3.h"


/*
    Create a cache by reading inputs from stdin
*/
Cache* createCache()
{
    int i;
    int currentSize=0;
    const char delimiter[2] =" ";
    char *token;
    char line[1000];
    Cache *cache=(Cache*) malloc(sizeof(Cache));
    DomainFreqNode *prev;
    DomainFreqNode *curr;
    CacheNode *prevCNode;
    CacheNode *currCNode;

    scanf("%d %d\n",&cache->cacheLimit,&cache->mediaCount);


    for (i = 0; i < cache->mediaCount; ++i) {
        CacheNode *cacheNode=(CacheNode*) malloc (sizeof(CacheNode));
        Media *media=(Media*) malloc (sizeof(Media));
        DomainFreqList *domainFreqList=(DomainFreqList*) malloc(sizeof(DomainFreqList));

        fgets(line,1000,stdin);

        /* get the first token */
        token = strtok(line, delimiter);
        media->name=(char*) malloc (sizeof(token));
        strcpy(media->name,token);
        token= strtok(NULL,delimiter);
        media->size= atoi(token);
        token= strtok(NULL,delimiter);
        currentSize+=media->size;
        /* walk through other tokens */
        while( token != NULL ) {
            DomainFreqNode *domainFreqNode=(DomainFreqNode*) malloc(sizeof(DomainFreqNode));
            domainFreqNode->name=(char*) malloc (sizeof(token));
            strcpy(domainFreqNode->name,token);
            token= strtok(NULL,delimiter);
            domainFreqNode->freq= atoi(token);
            token= strtok(NULL,delimiter);
            domainFreqNode->next= NULL;
            domainFreqNode->prev= NULL;
            
            if(domainFreqList->head==NULL){
                domainFreqNode->prev= NULL;
                domainFreqList->head=domainFreqNode;
                domainFreqList->tail=domainFreqNode;
            }else{/*burada sort işlemini yap!!!*/
                prev=NULL;
                curr=domainFreqList->head;
                while(curr){
                    if(domainFreqNode->freq>domainFreqList->head->freq){
                        domainFreqNode->prev=prev;
                        domainFreqNode->next=curr;
                        curr->prev=domainFreqNode;
                        domainFreqList->head=domainFreqNode;
                        domainFreqList->tail=curr;
                        break;
                    }else if(domainFreqNode->freq>curr->freq){
                        domainFreqNode->prev=prev;
                        prev->next=domainFreqNode;
                        domainFreqNode->next=curr;
                        curr->prev=domainFreqNode;
                        if(curr->next==NULL){
                            domainFreqList->tail=curr;
                            break;
                        }
                        break;
                    }else if(domainFreqNode->freq==curr->freq){
                        if(strcmp(domainFreqNode->name,curr->name)<0&&domainFreqList->head==curr){
                            domainFreqNode->prev=prev;
                            domainFreqNode->next=curr;
                            curr->prev=domainFreqNode;
                            domainFreqList->head=domainFreqNode;
                            domainFreqList->tail=curr;
                            break;
                        }else if(strcmp(domainFreqNode->name,curr->name)<0&&domainFreqList->head!=curr){
                            domainFreqNode->prev=prev;
                            prev->next=domainFreqNode;
                            domainFreqNode->next=curr;
                            curr->prev=domainFreqNode;
                            if(curr->next==NULL){
                                domainFreqList->tail=curr;
                                break;
                            }
                            break;
                        }
                    }else if(curr->next==NULL){
                        domainFreqNode->prev=curr;
                        domainFreqNode->next=NULL;
                        curr->next=domainFreqNode;
                        domainFreqList->tail=domainFreqNode;
                        break;
                    }
                    prev=curr;
                    curr=curr->next;
                }
                
            }
        }
        
        cacheNode->domainFreqList=domainFreqList;
        cacheNode->media=*media;

        if (i == 0) {
            cacheNode->prev=NULL;
            cacheNode->next=NULL;
            cache->head = cacheNode;
            cache->tail = cacheNode;
            currCNode=cacheNode;
            prevCNode=NULL;
        } else{
            cacheNode->prev=currCNode;
            cacheNode->next=NULL;
            currCNode->next=cacheNode;
            prevCNode=currCNode;
            currCNode=cacheNode;
            cache->tail = cacheNode;
        }

    }
    cache->currentSize=currentSize;
    return cache;
}

/*
    Prints cache information and its contents
*/
void printCache(Cache* cache){
    int i;
    DomainFreqNode *prev;
    DomainFreqNode *curr;
    CacheNode *prevCNode;
    CacheNode *currCNode;
    
    if(cache->mediaCount==0){
        printf("The Cache is Empty\n");
        return;
    }
    
    printf("-------------- Cache Information --------------\n");
    printf("Cache Limit: %d KB\n",cache->cacheLimit);
    printf("Current Size: %d KB\n",cache->currentSize);
    printf("Media Count: %d\n",cache->mediaCount);
    printf("Cache Media Info:\n");
    currCNode=cache->head;
    for (i = 0; i < cache->mediaCount; ++i) {
        
        printf("\tName: %s\tSize: %d KB\n",currCNode->media.name,currCNode->media.size);
        
        printf("\t------- Media Domain Frequencies -------\n");
        curr=currCNode->domainFreqList->head;
        while(curr){
            printf("\t\tName: %s\tFreq: %d\n",curr->name,curr->freq);
            curr=curr->next;
        }
        printf("\t----------------------------------------\n");
        currCNode=currCNode->next;
    }
    printf("----------------------------------------------\n");
}


/*
    Adds media to the cache
*/
CacheNode* addMediaRequest(Cache* cache, Media media, char* domain)
{
    int i;
    DomainFreqNode *prev;
    DomainFreqNode *curr;
    CacheNode *prevCNode;
    CacheNode *currCNode=NULL;
    CacheNode *newNode=(CacheNode*) malloc (sizeof(CacheNode));
    
    CacheNode *tempCNode=cache->head;
    
    for (i = 0; i < cache->mediaCount; ++i) {
        if(strcmp(tempCNode->media.name,media.name)==0){
            currCNode=tempCNode;
            break;
        }
        if(tempCNode){
            tempCNode=tempCNode->next;
        }
    }
    
    
    if(currCNode!=NULL){
        CacheNode *prevCNode=currCNode->prev;
        DomainFreqList *domainFreqList=currCNode->domainFreqList;
        DomainFreqNode *domainFreqNode=domainFreqList->head;
        
            
            if(domainFreqList->head==NULL){
                DomainFreqNode *domainFreqNode=(DomainFreqNode*) malloc(sizeof(DomainFreqNode));
                domainFreqNode->name=(char*) malloc (sizeof(domain));
                strcpy(domainFreqNode->name,domain);
                domainFreqNode->freq=1;
                domainFreqNode->prev=NULL;
                domainFreqNode->next=NULL;
                domainFreqList->head=domainFreqNode;
                domainFreqList->tail=domainFreqNode;
            }else{
                DomainFreqNode *domainFreqNode=(DomainFreqNode*) malloc(sizeof(DomainFreqNode));
                domainFreqNode->name=(char*) malloc (sizeof(domain));
                strcpy(domainFreqNode->name,domain);
                domainFreqNode->freq=1;
                domainFreqNode->prev=NULL;
                domainFreqNode->next=NULL;
                
                prev=NULL;
                curr=domainFreqList->head;
                while(curr){
                    if(strcmp(curr->name,domain)==0){
                        if(curr==domainFreqList->head){
                            domainFreqNode->freq+=curr->freq;
                            prev=curr;
                            curr=curr->next;
                            prev->next=NULL;
                            if(curr){
                                curr->prev=NULL;
                            }
                            domainFreqList->head=curr;
                            if(curr==NULL){
                                domainFreqList->tail=curr;
                            }else if(curr->next==NULL){
                                domainFreqList->tail=curr;
                            }
                            break;
                        }else{
                            domainFreqNode->freq+=curr->freq;
                            if(curr->next==NULL){
                                prev->next=curr->next;
                                curr->prev=NULL;
                                curr->next=NULL;
                            }else{
                                prev->next=curr->next;
                                curr->prev=NULL;
                                curr->next->prev=prev;
                                curr->next=NULL;
                            }
                            break;
                        }
                    }
                    prev=curr;
                    curr=curr->next;
                }
            
            /**/
                prev=NULL;
                curr=domainFreqList->head;
                while(curr){
                    if(domainFreqNode->freq>domainFreqList->head->freq){
                        domainFreqNode->prev=prev;
                        domainFreqNode->next=curr;
                        curr->prev=domainFreqNode;
                        domainFreqList->head=domainFreqNode;
                        domainFreqList->tail=curr;
                        break;
                    }else if(domainFreqNode->freq>curr->freq){
                        domainFreqNode->prev=prev;
                        prev->next=domainFreqNode;
                        domainFreqNode->next=curr;
                        curr->prev=domainFreqNode;
                        if(curr->next==NULL){
                            domainFreqList->tail=curr;
                            break;
                        }
                        break;
                    }else if(domainFreqNode->freq==curr->freq){
                        if(strcmp(domainFreqNode->name,curr->name)<0&&domainFreqList->head==curr){
                            domainFreqNode->prev=prev;
                            domainFreqNode->next=curr;
                            curr->prev=domainFreqNode;
                            domainFreqList->head=domainFreqNode;
                            domainFreqList->tail=curr;
                            break;
                        }else if(strcmp(domainFreqNode->name,curr->name)<0&&domainFreqList->head!=curr){
                            domainFreqNode->prev=prev;
                            prev->next=domainFreqNode;
                            domainFreqNode->next=curr;
                            curr->prev=domainFreqNode;
                            if(curr->next==NULL){
                                domainFreqList->tail=curr;
                                break;
                            }
                            break;
                        }
                    }else if(curr->next==NULL){
                        domainFreqNode->prev=curr;
                        domainFreqNode->next=NULL;
                        curr->next=domainFreqNode;
                        domainFreqList->tail=domainFreqNode;
                        break;
                    }
                    prev=curr;
                    curr=curr->next;
                }
            
                if(domainFreqList->head==NULL){
                    domainFreqList->head=domainFreqNode;
                    domainFreqList->tail=domainFreqNode;
                }
            
            }
            /**/
            
            if(prevCNode!=NULL){
                prevCNode->next=currCNode->next;
            }
            if(currCNode->next!=NULL){
                currCNode->next->prev=prevCNode;
            }
            currCNode->prev=NULL;
            currCNode->next=cache->head;
            cache->head->prev=currCNode;
            cache->head=currCNode;
            return currCNode;
    
        
    }else{
        DomainFreqList *domainFreqList=(DomainFreqList*) malloc(sizeof(DomainFreqList));
        DomainFreqNode *domainFreqNode=(DomainFreqNode*) malloc(sizeof(DomainFreqNode));
        
        newNode->media=media;
        newNode->prev=NULL;
        newNode->next=NULL;

        domainFreqNode->name=(char*) malloc (sizeof(domain));
        strcpy(domainFreqNode->name,domain);

        domainFreqNode->freq=1;
        domainFreqNode->prev=NULL;
        domainFreqNode->next=NULL;

        domainFreqList->head=domainFreqNode;
        domainFreqList->tail=domainFreqNode;

        newNode->domainFreqList=domainFreqList;
        currCNode=cache->head;
        if(cache->cacheLimit>=media.size+cache->currentSize){
            newNode->next=currCNode;
            currCNode->prev=newNode;
            cache->head=newNode;
            cache->currentSize+=media.size;
            cache->mediaCount++;
            return newNode;
        }else{
            while(cache->cacheLimit<media.size+cache->currentSize){
                deleteMedia(cache,cache->tail->media.name);
            }
            if(cache->head==NULL){
                cache->head=newNode;
            }else{
                newNode->next=currCNode;
                currCNode->prev=newNode;
                cache->head=newNode;
            }
            cache->currentSize+=media.size;
            cache->mediaCount++;
            return newNode;
        }
    }
}

/*
    Finds the corresponding media's node in the cache
    Return NULL if it is not found
*/
CacheNode* findMedia(Cache* cache, char* name)
{
    int i;
    CacheNode *currCNode=cache->head;
    
    for (i = 0; i < cache->mediaCount; ++i) {
        
        if(strcmp(currCNode->media.name,name)==0){
            return currCNode;
        }
        if(currCNode){
            currCNode=currCNode->next;
        }
    }
    
    return NULL;
}

/*
    Finds a media from its name and deletes it's node from the cache
    Do not do anything if media is not found
*/
void deleteMedia(Cache* cache, char* name)
{
    int i;
    DomainFreqNode *prev;
    DomainFreqNode *curr;
    CacheNode *prevCNode;
    CacheNode *currCNode;
    
    prevCNode=NULL;
    currCNode=cache->head;
    for (i = 0; i < cache->mediaCount; ++i) {
        
        if(strcmp(currCNode->media.name,name)==0){
            if(currCNode==cache->head){
                cache->currentSize=cache->currentSize-currCNode->media.size;
                if(currCNode->next==NULL){
                    currCNode=NULL;
                    cache->tail=NULL;
                    cache->head=NULL;
                }else{
                    currCNode=currCNode->next;
                    currCNode->prev->next=NULL;
                    cache->head=currCNode;
                }
                cache->mediaCount--;
                return;
            }else if(currCNode==cache->tail){
                cache->currentSize=cache->currentSize-currCNode->media.size;
                if(currCNode->prev==NULL){
                    currCNode=NULL;
                    cache->tail=NULL;
                    cache->head=NULL;
                }else{
                    prevCNode->next=NULL;
                    currCNode->prev=NULL;
                    cache->tail=prevCNode;
                }
                cache->mediaCount--;
                return;
            }else{
                cache->currentSize=cache->currentSize-currCNode->media.size;
                prevCNode->next=currCNode->next;
                currCNode->prev=NULL;
                currCNode=currCNode->next;
                currCNode->prev=prevCNode;
                cache->mediaCount--;
                return;
            }
        }
        
        prevCNode=currCNode;
        currCNode=currCNode->next;
    }
}

