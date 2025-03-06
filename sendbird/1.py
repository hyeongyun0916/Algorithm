'''
// # Problem
// In chat messages, it is often necessary to block certain kinds of messages depending on what is in the message. One filter we have is a domain filter which will block all messages containing a URL pointing to a certain domain (e.g. 4chan). How would you implement such a filter?

// -You can assume that you have a method to extract a list of URLs contained in a message.
// -All subdomains of a domain should also be blocked
//   -Only applies to sibling and descendent subdomains (see Example #2)
// -You can assume that all URLs in a message have no more than 5 domain parts (a.b.c.d.com)
// -You can assume that all URLs in a message have at least 2 domain parts (a.com)
// -You can assume that all URLs, in a message or blocklist, is at most 2000 characters
// -You can pre-process the blocklist in any way you'd like


// # Input
// A data structure with domains (blocklist)
// A list of URLs in a message

// # Output
// A boolean value indicating whether or not the message should be blocked

// Example #1
// blocklist = {"google.com", "daum.net"}
// user_urls = {"images.google.com", "example.com"}
// → true (should be blocked)

// Example #2
// blocklist = {"images.google.com"}
// user_urls = {"books.google.com"}
// → false (should not be blocked)

// Example #3
// blocklist = {"google.com"}
// user_urls = {"google.com.au"}
// → false (should not be blocked)

// Example #4
// blocklist = {"google.com"}
// user_urls = {"notgoogle.com"}
// → false (should not be blocked)

// Example #5: An often-failing edge case! Strongly recommended to run.
// blocklist = {"images.google.com", "google.com"}
// user_urls = {"books.google.com"}
// -> true



'''
# len(blocklist) N
# len(user_urls) M

# O(N) + O(M)

new_blocklist = {}


def set_new_blocklist(small_new_blocklist, splited):
    if splited[-1] in small_new_blocklist and len(small_new_blocklist[splited[-1]]) == 0:
        return
    if len(splited) == 1:
        small_new_blocklist[splited[-1]] = {}
        return
    if splited[-1] not in small_new_blocklist:
        small_new_blocklist[splited[-1]] = {}
    set_new_blocklist(small_new_blocklist[splited[-1]], splited[:-1])


def should_block(blocklist, user_urls):
    global new_blocklist
    new_blocklist = {}
    for block in blocklist:
        splited_block = block.split('.')
        set_new_blocklist(new_blocklist, splited_block)

    for user_url in user_urls:
        splited_user_url = user_url.split('.')
        n = len(splited_user_url)
        check = False
        temp_block = new_blocklist
        for i in range(n-1, -1, -1):
            if splited_user_url[i] in temp_block:
                temp_block = temp_block[splited_user_url[i]]
                if len(temp_block) == 0:
                    check = True
            else:
                break
        if check:
            return True

    return False


# print(should_block({"google.com", "daum.net"}, {"images.google.com", "example.com"}))
# print(should_block({"images.google.com"}, {"books.google.com"}))
# print(should_block({"google.com"}, {"google.com.au"}))
# print(should_block({"google.com"}, {"notgoogle.com"}))
print(should_block({"images.google.com", "google.com"}, {"books.google.com"}))
