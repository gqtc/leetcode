/*****************************************************
You are given a string, s, and a list of words, words, that are all of 
the same length. Find all starting indices of substring(s) in s that is 
a concatenation of each word in words exactly once and without 
any intervening characters.

	For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashnode
{
	char *str;
	int nums;
	struct hashnode *next;	
}HashNode;

#define NHASH 31
#define MULT 31

unsigned int hash(char *p)
{
    unsigned int h = 0;
    for (; *p; p++)
        h = MULT *h + *p;
    return h % NHASH;
}


int isfindword(char *word, HashNode **wordhash, int hashlen)
{
	int hashvalue = hash(word);
	HashNode *ptr = wordhash[hashvalue];

	while(ptr != NULL)
	{
		if(ptr->str == NULL)	return 0;
		if(strcmp(ptr->str, word) == 0)
		{
			return ptr->nums;
		}
		ptr = ptr->next;
	}
	return 0;
}

void  freehash(HashNode **wordhash, int hashsize)
{
	int i = 0; 
	HashNode *ptr = NULL;
	HashNode *qtr = ptr;

	while(i < hashsize)
	{
		ptr = wordhash[i];
		while(ptr != NULL)
		{
			qtr = ptr;
			ptr = ptr->next;
			free(qtr->str);
			free(qtr);
		}
		wordhash[i] = NULL;
		i++;
	}
    return;
}

int inserttohash(HashNode **map, char *word, int wordlen)
{
	int hashvalue = hash(word);

	HashNode *hp = map[hashvalue];
	HashNode *hq = hp;
	while(hp != NULL)
	{
		if(strcmp(hp->str, word) == 0)
		{
			hp->nums += 1;
			break;
		}
		else
		{
			hq = hp;
			hp = hp->next;
		}
	}
	if(hp == NULL)
	{
		hp = calloc(1, sizeof(HashNode));
		hp->str = calloc(wordlen+1, sizeof(char));
		memcpy(hp->str, word, wordlen);
		hp->nums= 1;
		if(map[hashvalue] == NULL)	map[hashvalue] = hp;
		else	hq->next = hp;
	}
	return hp->nums;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize)
{
	int hashlen = NHASH;
	HashNode **constwordhash = calloc(hashlen, sizeof(HashNode *));
	HashNode **acthash = calloc(hashlen, sizeof(HashNode *));
	int i;
	int hashvalue;
	int wordlen = strlen(words[0]);
	for(i = 0; i < wordsSize; i++)
	{
		inserttohash(constwordhash, words[i], wordlen);
	}	

	int findnums = 0;
	int getindexres = -1;
	int *res = calloc(strlen(s), sizeof(int));
	int resindex = 0;
	int left = 0;
	i = left;
	int forcounts = 0;
	int tstrlen = strlen(s);
	while(i < tstrlen && left <= tstrlen-wordsSize*wordlen)
	{
		forcounts++;
		char *word = calloc(wordlen+1, sizeof(char));
		memcpy(word, s+i, wordlen);
		
		getindexres = isfindword(word, constwordhash, hashlen);
		
		if(getindexres == 0 || getindexres < inserttohash(acthash, word, wordlen))
		{
			findnums = 0;
			left++;
			i = left;
			freehash(acthash, hashlen);	
			free(word);
			continue;
		}
		else
		{
			free(word);
			findnums++;
			if(findnums == wordsSize)
			{
				res[resindex++] = left;
				findnums = 0;
				left++;
				i = left;
				freehash(acthash, hashlen); 
				continue;
			}
			i += wordlen;
		}
	}


	*returnSize = resindex;
	freehash(constwordhash, hashlen);
	freehash(acthash, hashlen);
	free(constwordhash);
	free(acthash);
 	return res;
}


int main()
{
	char *str = "miudowshwyqwmysgveoymhuqvbuvtcdhmzkavejscaqqa\
kwwpnwbuqtrtnomruvdthfplpjppzipjenarjdozwfsmugdobjjioyvdhnsivks\
bxuvhyjguqbgmhmclvmvjkrnuehcbrweprzypiglbhunrgqebezmoqzkwjnzclet\
edrtoyhphbeyhwckacwruydtjqslewficyeqwlheonexkjjmnffhfjcqbvcftjqvh\
unghumxkqwuzfiomowszaiavmirvymfualbwxagpwcrbnfnbdhaescbekscihjejuh\
fthokdsbgfjwimdksxnwezogixroglwogdeqjwupcdlmrrxmomislyavwrkeegskjwd\
uvzkzexlxokjdwtxiuyfqrpwwxpijnndimnhqlvobfzeeteonctfvlbriscrgpvqekyu\
vvkxakdefhsulozhzcahvebdwytaitwgohfrtkxysssfgtohvpqsvrvrprramogdvluov\
topngvtzlcwatpwmmnefhesvmvszrgumumacjvbuyzxtqvfdklirpcmdxecqmzdgldkwan\
qynnrdkzivkrmcvzfvfilshqauvlqwyiunyorinzdzsqbqrhlyrwqaptukgmggubusrnbem\
gdhyhxpqkqhgghvbdihpoojrkeixfmlnssmbrdrbtakcjhdopndedovnsekzsvnmqzpjcilw\
ixytedhwqmatbxgtdsvyoimghcplkchvzhoglycbkevlddhhwcfmmtstvhgimodnvttirxkc\
dhphmyqicxuoqojmyqwkgzzdsvmmsyqyhhftgxekuybkpmyneuzkvyqotccocsmjztehqismj\
vwyhxnmtmwpmofgqhuuzifabkitscfdxdbeaqswcplpdqxwztsybyaekizekgijjlqmciiezvv\
fludmnvkqvkwfvvkhburnfjbjrjqrglwtgzfvwrmsdkzyglijfbynkzwbkmuqasjirodqhrilcj\
jkvtvcuupetoigacwaviioyogghorjacvvyrxsnpzgdhodlngivqzvefbowuxwzvrxmqrzfqhixw\
oljwtgmsbtafhwzgsablzpbrojhythwjshfnnsiqnixuezcyzejztmqkvzkrggaangqcayupislor\
nmqtvrnjjzfjjyrpyuegmiimcxuuiinywgrrxgajfhuqhlhghlovtxhywbuhlifhoyanfdwmmqduek\
cnyqjtpqrouovhycrmcrbhwawjqzfwlhmjzvdrnwfjmcrkgiwibasyaojspqraxdmyyrpnnuxayome\
yjnzlfzntkfiawkzbwyznnndkkfiarnycczphzccjkmmgwlktlj\
izynlkutkmikqkkgtlivwshibewlzhwjixxtjrpwfzgwkqeddobajiimoezpmv";


	int wordcounts = 21;
	char **words = calloc(wordcounts, sizeof(char *));

	int i = 0;

	words[i++] = "mhuqvbuvtcdhmzkavejsca";
	words[i++] = "qqakwwpnwbuqtrtnomruvd";
	words[i++] = "thfplpjppzipjenarjdozw";
	words[i++] = "fsmugdobjjioyvdhnsivks";
	words[i++] = "bxuvhyjguqbgmhmclvmvjk";
	words[i++] = "rnuehcbrweprzypiglbhun";
	words[i++] = "rgqebezmoqzkwjnzcleted";
	words[i++] = "rtoyhphbeyhwckacwruydt";
	words[i++] = "jqslewficyeqwlheonexkj";
	words[i++] = "jmnffhfjcqbvcftjqvhung";
	words[i++] = "humxkqwuzfiomowszaiavm";
	words[i++] = "irvymfualbwxagpwcrbnfn";
	words[i++] = "bdhaescbekscihjejuhfth";
	words[i++] = "okdsbgfjwimdksxnwezogi";
	words[i++] = "xroglwogdeqjwupcdlmrrx";
	words[i++] = "momislyavwrkeegskjwduv";
	words[i++] = "zkzexlxokjdwtxiuyfqrpw";
	words[i++] = "wxpijnndimnhqlvobfzeet";
	words[i++] = "eonctfvlbriscrgpvqekyu";
	words[i++] = "vvkxakdefhsulozhzcahve";
	words[i++] = "bdwytaitwgohfrtkxysssf";

	int reslen = 0;
	int *res = NULL;
	res = findSubstring(str, words, wordcounts, &reslen);


	for(i = 0 ; i < reslen; i++)
 	{
		printf("%d\n", res[i]);
 	}

 	free(res);
 	free(words);
}

