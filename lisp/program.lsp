; f1: Check if the list contains at least one atom (non-list element)
; Returns t if any element is an atom, nil if list is empty or all elements are lists
(defun f1 (lst)
    (cond
        ((null lst) nil)          ; Empty list - no atoms found
        ((atom (car lst)) t)      ; Found an atom - return true
        (t (f1 (cdr lst)))        ; Current element is a list, check rest
    )
)

; f2: Count the number of sublists that have exactly one element
; Returns the count of single-element sublists
(defun f2 (lst)
    (cond
        ((null lst) 0)            ; Empty list - no sublists to count
        ((and (listp (car lst)) (equal (length (car lst)) 1))
            (+ 1 (f2 (cdr lst))))   ; Found single-element sublist, count it
        (t (f2 (cdr lst)))        ; Not a single-element sublist, continue
    )
)

; f3: Filter a list to keep only odd numbers
; Returns a new list containing only the odd numbers from the input
(defun f3 (lst)
    (cond
        ((null lst) nil)          ; Empty list - return empty list
        ((oddp (car lst))
            (cons (car lst) (f3 (cdr lst))))  ; Odd number - include it
        (t (f3 (cdr lst)))        ; Even number - skip it
    )
)

; f4: Find the minimum value in a list of numbers
; Returns the smallest number in the list
(defun f4 (lst)
    (cond
        ((null (cdr lst)) (car lst))  ; Only one element - it's the minimum
        ((< (car lst) (f4 (cdr lst))) (car lst))  ; First element is smaller
        (t (f4 (cdr lst)))            ; Minimum is in the rest of the list
    )
)

; f5: Reverse a list
; Returns a new list with elements in reverse order
(defun f5 (lst)
    (cond
        ((null lst) nil)          ; Empty list - return empty list
        (t (append (f5 (cdr lst)) (list (car lst))))  ; Append first element to end of reversed rest
    )
)

; f6: Extract every other element starting from the first
; Returns a list with elements at positions 1, 3, 5, etc.
(defun f6 (lst)
    (cond
        ((null lst) nil)          ; Empty list - return empty list
        (t (cons (car lst) (f6 (cdr (cdr lst)))))  ; Take first, skip second, recurse
    )
)

; f7: Get the element at a specific position (1-based indexing)
; Returns the element at position 'ptr' in the list
(defun f7 (lst ptr)
    (cond
        ((null lst) nil)          ; Empty list or position out of bounds
        ((equal ptr 1) (car lst)) ; Found the target position
        (t (f7 (cdr lst)(- ptr 1))) ; Move to next element, decrement position
    )
)

; f8: Calculate sum of squares of all numbers in a nested list structure
; Returns the sum of squares of all atomic numbers found
(defun f8 (lst)
    (cond
        ((null lst) 0)            ; Empty list - sum is 0
        ((listp (car lst))        ; If first element is a sublist
            (+ (f8 (car lst)) (f8 (cdr lst))))  ; Process sublist and rest
        (t (+ (* (car lst) (car lst)) (f8 (cdr lst))))  ; Square the number and add to rest
    )
)

; my_member: Check if element x is in the list
; Returns t if x is found in lst, nil otherwise
(defun my_member (x lst)
    (cond
        ((null lst) nil)          ; Empty list - element not found
        ((equal x (car lst)) t)   ; Found the element
        (t (my_member x (cdr lst))) ; Check rest of list
    )
)

; f9: Remove duplicate elements from a list (keep first occurrence)
; Returns a list with duplicates removed
(defun f9 (lst)
    (cond
        ((null lst) nil)          ; Empty list - return empty list
        ((my_member (car lst) (cdr lst))  ; If current element appears later
            (f9 (cdr lst)))       ; Skip it (remove duplicate)
        (t (cons (car lst) (f9 (cdr lst))))  ; Keep it and process rest
    )
)

; f10: Find intersection of two lists (elements common to both)
; Returns a list of elements that appear in both lst1 and lst2
(defun f10 (lst1 lst2)
    (cond
        ((null lst1) nil)         ; Empty first list - no intersection
        ((null lst2) nil)         ; Empty second list - no intersection
        ((my_member (car lst1) lst2)  ; If first element of lst1 is in lst2
            (cons (car lst1) (f10 (cdr lst1) lst2)))  ; Include it in result
        (t (f10 (cdr lst1) lst2)) ; Not in intersection, check rest
    )
)
