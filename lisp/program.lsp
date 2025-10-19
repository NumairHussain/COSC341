(defun f1 (lst)
  (cond
    ((null lst) nil)
    ((atom (car lst)) t)
    (t (f1 (cdr lst)))
  )
)

(defun f2 (lst)
  (cond
    ((null lst) 0)
    ((and (listp (car lst)) (= (length (car lst)) 1))
     (+ 1 (f2 (cdr lst))))
    (t (f2 (cdr lst)))
  )
) 

(defun f3 (lst)
  (cond
    ((null lst) nil)
    ((oddp (car lst))
     (cons (car lst) (f3 (cdr lst))))
    (t (f3 (cdr lst)))
  )
)

(defun f4 (lst)
  (cond
    ((null lst) nil)
    ((null (cdr lst)) (car lst))
    (t (min (car lst) (f4 (cdr lst))))
  )
)

(defun f5 (lst)
  (cond
    ((null lst) nil)
    (t (append (f5 (cdr lst)) (list (car lst))))
  )
)

(defun f6 (lst)
  (cond
    ((null lst) nil)
    ((null (cdr lst)) (list (car lst)))
    (t (cons (car lst) (f6 (cdr (cdr lst)))))
  )
)

(defun f7 (lst n)
  (cond
    ((null lst) nil)
    ((= n 1) (car lst))
    (t (f7 (cdr lst) (- n 1)))
  )
)

(defun f8 (lst)
  (cond
    ((null lst) 0)
    ((atom (car lst))
     (+ (* (car lst) (car lst)) (f8 (cdr lst))))
    (t (+ (f8 (car lst)) (f8 (cdr lst))))
  )
)

(defun f9 (lst)
  (cond
    ((null lst) nil)
    ((f9helper (car lst) (cdr lst)) 
     (f9 (cdr lst)))
    (t (cons (car lst) (f9 (cdr lst))))
  )
)

(defun f9helper (x lst)
  (cond
    ((null lst) nil)
    ((equal x (car lst)) t)
    (t (f9helper x (cdr lst)))
  )
)

(defun f10 (lst1 lst2)
  (cond
    ((null lst1) nil)
    ((f10helper (car lst1) lst2)
     (cons (car lst1) (f10 (cdr lst1) lst2)))
    (t (f10 (cdr lst1) lst2))
  )
)

(defun f10helper (x lst)
  (cond
    ((null lst) nil)
    ((equal x (car lst)) t)
    (t (f10helper x (cdr lst)))
  )
)
