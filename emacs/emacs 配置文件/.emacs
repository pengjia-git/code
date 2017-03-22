;;(setq auto-save-default nil)
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(custom-enabled-themes (quote (misterioso)))
 '(show-paren-mode t))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(default ((t (:family "宋体" :foundry "outline" :slant normal :weight normal :height 98 :width normal)))))
;;去掉启动欢迎界面
(setq inhibit-startup-message t)

;;禁止自动保存
(auto-save-mode nil)

;;高亮显示匹配的括号
(show-paren-mode t)
;;改变emacs要求回答yes的行为
(fset 'yes-or-no-p 'y-or-n-p) 

;;显示行号
(require 'linum)
(global-linum-mode t)

(setq c-default-style "linux"
          c-basic-offset 4)

;;自动换行
(add-hook 'text-mode-hook 'turn-on-auto-fill)

;;todo 的item中插入时间
(setq org-log-done 'time)

(setq make-backup-files nil)

