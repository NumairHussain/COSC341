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