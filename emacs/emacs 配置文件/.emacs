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
 '(default ((t (:family "����" :foundry "outline" :slant normal :weight normal :height 98 :width normal)))))
;;ȥ��������ӭ����
(setq inhibit-startup-message t)

;;��ֹ�Զ�����
(auto-save-mode nil)

;;������ʾƥ�������
(show-paren-mode t)
;;�ı�emacsҪ��ش�yes����Ϊ
(fset 'yes-or-no-p 'y-or-n-p) 

;;��ʾ�к�
(require 'linum)
(global-linum-mode t)

(setq c-default-style "linux"
          c-basic-offset 4)

;;�Զ�����
(add-hook 'text-mode-hook 'turn-on-auto-fill)

;;todo ��item�в���ʱ��
(setq org-log-done 'time)

(setq make-backup-files nil)

